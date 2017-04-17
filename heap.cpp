
#include <iostream>
#include<stdlib.h>
using namespace std;

class heap1
{
private:int a[100],n;
public:
heap1()
{
	a[0]=0;
	n=0;

}
void accept_max();
void accept_min();
void makeheap_max(int data);
void makeheap_min(int data);
void max_heap(int i);
void min_heap(int i);
void display();
};
void heap1::accept_max()
{
	int data;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	cout<<"Enter marks"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		makeheap_max(data);
	}
	cout<<"The maximum marks obtained is:"<<a[1]<<endl;
}

void heap1::accept_min()
{
	int data;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	cout<<"Enter marks:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		makeheap_min(data);
	}
	cout<<"Minimum marks obtained:"<<a[1]<<endl;
}


void heap1::makeheap_min(int data)
{
a[++a[0]]=data;
min_heap(a[0]);
}





void heap1::makeheap_max(int data)
{
	a[++a[0]]=data;
	max_heap(a[0]);
}

void heap1::max_heap(int i)
{
	int temp;
	while(i>1 && a[i]>a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}

}

void heap1::min_heap(int i)
{
	int temp;
	while(i>1 &&a[i]<a[i/2])
	{
		temp=a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}

}


void heap1::display()
{
	cout<<"Entered marks are:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"";
	}
	cout<<endl;
}

int main()
{
	heap1 h;
	int ch;
do
{
	cout<<"1.Accept & make Maxheap    2.Accept & make Minheap    3.Display    4.Exit"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
		h.accept_max();
		break;
	case 2:
		h.accept_min();
		break;
	case 3:h.display();
	break;
	case 4:exit(0);
	}
}while(ch!=4);
return 0;
}
