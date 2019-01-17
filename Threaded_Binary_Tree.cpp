#include<iostream.h>

using namespace std; 


class thread
{
	enum boolean left;
	thread *lchild;
	int data;
	thread *rchild;
	enum boolean right;
public:
	void insert(int num);
	void inorder();
	void inorder_new();
	void search(int);

};
thread *head=NULL;
void thread::insert(int num)
{
	if(head==NULL)

	{
		head=new thread;
		head->left=false;
		head->data=num;
		head->lchild=NULL;
		head->rchild=NULL;
		head->right=false;
		return;
	}
	thread *temp=new thread;
	temp->left=true;
	temp->data=num;
	temp->right=true;
	if(head->lchild==NULL)
	{
		head->lchild=temp;
		temp->lchild=NULL;
		temp->rchild=head;
		return;
	}
	else
	{
		if(head->rchild==NULL)
		{
			head->rchild=temp;
			temp->lchild=head;
			temp->rchild=NULL;
			return;
		}
	}
	thread *ptr=head;
	while(ptr->right!=true)
		ptr=ptr->rchild;
	if(ptr->left==true)
	{
		temp->lchild=ptr->lchild;
		temp->rchild=ptr;
		ptr->lchild=temp;
		ptr->left=false;
	}
	else
	{
		temp->lchild=ptr;
		temp->rchild=NULL;
		ptr->rchild=temp;
		ptr->right=false;
	}
}

void thread::inorder()
{
	thread *p=head;
	if(head->rchild==NULL&amp;&amp;head->lchild==NULL)
	{
		cout<<head->data<<" ";
		return;
	}
	while(p)
	{
		while(p->left!=true) p=p->lchild;
		cout<<p->data<<" ";
		while(p->right==true)
		{
			p=p->rchild;
			if(p==NULL) break;
			cout<<p->data<<" ";
		}
		if(p!=NULL) p=p->rchild;
	}
}
void thread::inorder_new()
{
	thread *p=head->lchild;
	while(p)
	{
		while(p->left!=true) p=p->lchild;
		cout<<p->data<<" ";
		while(p->right==true)
		{
			p=p->rchild;
			cout<<p->data<<" ";
		}
		p=p->rchild;
	}
}

int main()
{
	int ch,ele;
	thread t;
	while(1)
	{
		clrscr();
		cout<<"1. insert 2. inorder 3. search 4. exit\nEnter your choice: \n";
		cin>>ch;

		switch(ch)
		{
			case 1: cout<<"Enter the element to be inserted: ";
			cin>>ele;
			t.insert(ele);
			t.inorder_new();
			getch();
			break;
			case 2: t.inorder();getch();break;
			case 4: exit(0);break;
		}
	}
}