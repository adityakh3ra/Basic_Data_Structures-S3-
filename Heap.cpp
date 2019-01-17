#include<iostream.h>

using namespace std; 

class maxheap
{
	int key;
	public: void insert();
	void sort();
	void adjust(maxheap*,int);
	void display();
	void delMax();
};
maxheap h[50];
int n=0;
void maxheap::insert()
{
	if(n==50)
		cout<<"\nHeap Is Full";
	else
	{
		maxheap temp;
		cout<<"\nEnter the element:";
		cin>>temp.key;
		int i=++n;
		while(i!=1&amp;&amp;temp.key>h[i/2].key)
		{
			h[i]=h[i/2];

			i=i/2;
		}
		h[i]=temp;
	}
	display();
}
void maxheap::sort()
{
	int m,temp;
	for(m=n;m>1;m--)
	{
// display();
		temp=h[1].key;
		h[1].key=h[m].key;
		h[m].key=temp;
		adjust(h,m-1);
		display();
	}
}

void maxheap::adjust(maxheap h[],int no)
{
	int j=1,temp,t;
	temp=h[j].key;
	while((j*2)<=no&amp;&amp; (j*2+1)<=no&amp;&amp;(h[j*2].key>temp||h[j*2+1].key>temp))
	{
		if(h[j*2].key>h[j*2+1].key)
		{
			h[j].key=h[j*2].key;
			h[j*2].key=temp;
			j=j*2;
		}
		else if(h[j*2].key<h[j*2+1].key)
		{
			h[j].key=h[j*2+1].key;
			h[j*2+1].key=temp;
			j=j*2+1;
		}
	}
	if((j*2)<=no)
	{
		if(h[j].key<h[2*j].key)
		{
			t=h[j].key;
			h[j].key=h[2*j].key;
			h[2*j].key=t;
		}

	}
}
void maxheap::display()
{ cout<<"\nHeap Is: \n";
for(int i=1;i<=n;i++)
	cout<<h[i].key<<"\t";
}
void maxheap::delMax()
{
	int temp;
	if(n==0)
	{
		cout<<"Heap is empty";
		return;
	}
	cout<<"Deleted item is"<<h[1].key;
	h[1].key=h[n].key;
	n--;
	int i=1;
	while(((2*i)<=n &amp;&amp; (2*i+1)<=n) &amp;&amp; (h[i].key<h[2*i].key || h[i].key<h[2*i+1].key))
	if(h[2*i].key>=h[2*i+1].key)

	{
		temp=h[i].key;
		h[i].key=h[2*i].key;
		h[2*i].key=temp;
		i=i*2;
	}
	else
	{
		temp=h[i].key;

		h[i].key=h[2*i+1].key;
		h[2*i+1].key=temp;
		i=2*i+1;
	}

	if(((2*i)<=n) &amp;&amp; h[i].key<h[2*i].key)
	{
		temp=h[i].key;

		h[i].key=h[2*i].key;
		h[2*i].key=temp;

		i=i*2;
	}
	if(((2*i+1)<=n) &amp;&amp; h[i].key<h[2*i+1].key)
	{
		temp=h[i].key;

		h[i].key=h[2*i+1].key;

		h[2*i+1].key=temp;

		i=i*2+1;
	}
}
int main()
{
	maxheap m;
	int ch;
	do
	{
		cout<<"\n1. Insert\n2. Sort\n3. Display\n4. delete\n0. Exit";
		cout<<"\n Enter Your Choice";
		cin>>ch;
		switch(ch)
		{
			case 1: m.insert();break;
			case 2: m.sort();break;
			case 3: m.display();break;
			case 4: m.delMax();break;
			case 0: break;
			default: cout<<"\nInvalid choice";break;
		}
	}while(ch!=0);
	return 1;
}