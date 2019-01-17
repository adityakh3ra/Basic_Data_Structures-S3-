#include<iostream>

using namespace std;

class clist
{
	int data;
	clist *next;
public:
	void insert();
	void dele();
	void disp();
	void init();
};
clist *headnode;
void clist::init()
{
	headnode=new clist;
	headnode->next=headnode;
}
void clist::insert()
{
	clist *temp,*curr;
	temp=new clist;
	cout<<"enter the data\n";
	cin>>temp->data;
	curr=headnode->next;
	if(headnode->next==headnode)
	{
		temp->next=headnode;
		headnode->next=temp;
	}
	else{
		while(curr->next!=headnode)
			curr=curr->next;
		temp->next=curr->next;
		curr->next=temp;
	}
}
void clist::dele()
{
	clist *curr=headnode->next,*prev;
	if(headnode->next==headnode)
		cout<<"List is empty\n";
	else{
		if(curr->next==headnode)
		{
			headnode->next=headnode;
			delete(curr);
		}
		else{

			while(curr->next!=headnode)
			{
				prev=curr;
				curr=curr->next;
			}
			prev->next=headnode;
			delete(curr);
		}
		disp();
	}
}
void clist::disp()
{
	clist *curr=headnode->next;
	if(headnode->next==headnode)
		cout<<"empty list";
	else
	{
		while(curr!=headnode)
		{
			cout<<"Address: "<<curr<<"\t data: "<<curr->data<<endl;
			getch();
			curr=curr->next;
		}
	}
}
int main()
{
	clist a;
	int ch;
	a.init();
	do
	{
		cout<<"\n1.insert\n2.delete\n3.disp\t\n4.exit\nEnter your choice: ";
		cin>>ch;
		switch (ch)
		{
			case 1: a.insert(); break;
			case 2: a.dele(); break;
			case 3: a.disp(); break;
			case 4: exit(0);
		}
	}while(1);
}