#include<iostream>

using namespace std;

class sparse
{
	int row;
	int col;
	int value;
public:
	sparse(int r,int c,int v)
	{
		row=r;
		col=c;
		value=v;

	}
	sparse()
	{
		row=col=value=0;
	}
	void disp(sparse*);
};
void sparse::disp(sparse a[])
{
	cout<<"row\tcol\tvalue\n";
	for(int i=0;i<=a[0].value;i++)
	{
		cout<<a[i].row<<"\t"<<a[i].col<<"\t"<<a[i].value<<"\n";
	}
}
int main ()
{
	sparse s[20],d; int r,c,v,val;
	cout<<"Enter the no. of rows:\n"; cin>>r;
	cout<<"Enter the no. of cols:\n"; cin>>c;
	cout<<"Enter the no. of values:\n"; cin>>v;
	s[0]=sparse(r,c,v);
	cout<<"Enter the elements of the sparse matrix:\n";
	for(int i=1;i<=v;i++)
	{
		cout<<"\nrow "<<i<<": "; cin>>r;
		cout<<"\ncol "<<i<<": "; cin>>c;
		cout<<"\nvalue "<<i<<": "; cin>>val;
		s[i]=sparse(r,c,val);
	}
	d.disp(s);
}