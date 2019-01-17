#include<iostream>

using namespace std;

class mstack
{
	int a[50], bottom[10], top[10], maxsize, ns;
	public: mstack();
	mstack(int,int);
	void push(int,int);
	int pop(int);
	void disp(int);
};
mstack::mstack()
{
	maxsize=10;
	ns=1;
}
mstack::mstack(int m,int n)
{
	maxsize=m;
	ns=n;
	for(int i=0;i<ns;i++)
		top[i]=bottom[i]=(maxsize/ns)*i-1;

}
void mstack::push(int ele,int i)
{
	if(top[i]==bottom[i+1]||top[i]==maxsize-1)
		cout<<"\nstack is full";
	else

		a[++top[i]]=ele;

}
int mstack::pop(int i)
{
	if(top[i]==bottom[i]){
		cout<<"\nstack is empty";
		return -1;
	}
	else return(a[top[i]--]);
}
void mstack::disp(int i)
{
	if(top[i]==bottom[i])
		cout<<"\nstack is empty";
	else{
		for(int k=bottom[i]+1;k<=top[i];k++)
			cout<<a[k]<<"\t";
	}

}
int main(){	
	mstack ms;int ch,m,n,i,ele;
	cout<<"\nenter the maximum size of the array:";
	cin>>m;
	cout<<"\nenter the no. of stack:";
	cin>>n;
	ms=mstack(m,n);
	do
	{
		cout<<"\n1.insert\n2.delete\n3.display\n0.exit";
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nenter the index of the stack:";
			cin>>i;
			cout<<"\nenter the element to be inserted:";
			cin>>ele;
			ms.push(ele,i);
			break;
			case 2: cout<<"\nenter the index of the stack:";
			cin>>i;
			cout<<ms.pop(i);
			break;
			case 3: cout<<"\nenter the index of the stack:";

			cin>>i;
			ms.disp(i);
			break;
			case 0: break;
			default: cout<<"\ninvalid input";
		}
	}while(ch!=0);
}
