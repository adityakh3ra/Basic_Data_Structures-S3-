#include<iostream>

using namespace std;
class list
{
	int data;
	list *next;
	list *prev;
public:
	void create();
	void insBefore();
	void insAfter();
	void delSpecific();
	void traverse();
	void reverse();
};
list *first=NULL;
void list::create()
{
	list *temp;
	temp=new list;
	cout<<"\nent er the data:";
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;

	if(first==NULL)
		first=temp;
	else
	{
		for(list *curr=first;curr->next!=NULL;curr=curr->next);
			curr->next=temp;
		temp->prev=curr;
	}
	traverse();
}
void list::insBefore()
{
	int x,flag=0;
	list *temp;
	temp=new list;
	cout<<"\nenter the element before which the node is to be inserted:";
	cin>>x;
	cout<<"\nenter the data for the node:";
	cin>>temp->data;
	temp->prev=temp->next=NULL;
	if(first==NULL)
		cout<<"\nlink is empty";
	else if(x==first->data)
	{
		temp->next=first;
		first=temp;
		flag=1;
	}
	else
	{
		for(list *curr=first;curr!=NULL;curr=curr->next)
		{
			if(curr->data==x)
			{
				temp->next=curr;
				temp->prev=curr->prev;
				curr->prev->next=temp;
				curr->prev=temp;
				flag=1;
				break;
			}
		}
	}
	if(flag==0) cout<<"\nnode not found";
	traverse();

}
void list::insAfter()
{
	int x,flag=0;
	list *temp;

	temp=new list;
	cout<<"\nenter the element after which the node is to be inserted:";
	cin>>x;
	cout<<"\nenter the data for the node:";
	cin>>temp->data;
	temp->prev=temp->next=NULL;
	if(first==NULL)
		cout<<"\nlink is empty";
	else if(first->data!=x)
	{
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
	else
	{
		for(list *curr=first;curr!=NULL;curr=curr->next){
			if(curr->data==x&amp;&amp;curr->next!=NULL)
			{
				temp->next=curr->next;
				curr->next->prev=temp;
				curr->next=temp;
				temp->prev=curr;
				flag=1;
				break;
			}
			else if(curr->data==x&amp;&amp;curr->next==NULL)
			{
				curr->next=temp;
				temp->prev=curr;
				flag=1;
				break;
			}
		}
	}
	if(flag==0) cout<<"\nnode not found\n";
	traverse();
}
void list::delSpecific()
{
	int x,flag=0;
	cout<<"\nenter the element to be deleted:";
	cin>>x;
	if(first==NULL)
		cout<<"\nlist is empty";
	else if(first->data==x)
	{
		list *temp=first;
		first=first->next;
		first->prev=NULL;

		delete temp;
		flag=1;
	}
	else
	{
		for(list *curr=first;curr!=NULL;curr=curr->next){
			if(curr->data==x&amp;&amp;curr->next!=NULL)
			{
				curr->prev->next=curr->next;
				curr->next->prev=curr->prev;
				delete curr;
				flag=1;
				break;
			}
			else if(curr->data==x)
			{
				curr->prev->next=NULL;
				delete curr;
				flag=1;
				break;
			}
		}
	}

	if(flag==0) cout<<"\nnode not found";

	traverse();

}
void list::traverse()
{
	if(first==NULL)
		cout<<"\nlist is empty";
	else
	{
		cout<<"\nthe list is:\n";
		for(list *curr=first;curr!=NULL;curr=curr->next)
			cout<<curr->data<<"\t";

	}
}
void list::reverse()
{
	list *temp1,*temp2;
	temp1=new list;
	temp2=new list;
	temp1=temp2=NULL;
	while(first!=NULL)
	{
		temp1=temp2;
		temp2=first;
		first=first->next;
		temp2->next=temp1;
		temp1->prev=temp2;
	}

	first=temp2;
	cout<<"\nreversed node is:";
	traverse();
}

int main()
{
	list l;
	int ch;
	do
	{
		cout<<"\n1 create\n2 insert before\n3 insert after\n4 delete

		specific\n5traverse\n6.reverse\n0.exit";
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:l.create();break;
			case 2:l.insBefore();break;
			case 3:l.insAfter();break;
			case 4:l.delSpecific();break;
			case 5:l.traverse();break;
			case 6:l.reverse();break;
			case 0:break;
			default:cout<<"\ninvalid input";break;
		}
	}while(ch!=0);

}