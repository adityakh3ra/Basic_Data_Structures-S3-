#include<iostream>

using namespace std;

class queue{
	int front,rear;
	int a[10];
	int maxsize;
	public: queue(){ 
		maxsize=4;front=rear=-1;
	}
	
	bool Isfull(){
		if(rear==maxsize-1)
			return true;
		return false;
	}
	bool Isempty(){ 
		if(rear==front)
			return true;
		return false;
	}
	void add(int x);
	void del();
	void display();
};

void queue::add(int x){ 
	if(Isfull())
		cout<<"Queue is full \n";
	else
		a[++rear]=x;
}

void queue::del(){
	if(Isempty())
		cout<<"queue is empty\n";
	else
		cout<<"deleted element is"<<(a[++front]);
}

void queue::display(){ 
	if(Isempty())
		cout<<"Queue is empty\n";
	else
		for(int i=front+1;i<=rear;i++)
			cout<<a[i];
	}

	int main(){
		queue s;
		int option,ele;
		char ch;
		do{
			cout<<"1.Insert\n2.Delete\n3.display\n4.exit\n";
			cin>>option;
			switch(option){
				case 1: cout<<"enter the element to be pushed\n";
				cin>>ele; s.add(ele);
				break;

				case 2: s.del();
				break;

				case 3: s.display();break;
			}
		}while(option<4);
	}
