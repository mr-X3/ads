/*
ASSIGNMENT NO:B-13
Title:Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.
linear probing without replacement without chaining
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/
#include<iostream>
#include<string.h>
using namespace std;

class hashtable
{
	public:
		char name[10];
		int no;
		hashtable()
		{
			strcpy(name,"NULL");
		}
};
class client
{
	hashtable hash[25];
	public:
		char a[10];
		int b;
	int returnVal(char x)
	{
		return (int)x-97;
	}
	int insert()
	{
		int w=0;
		char m;
		int i,j;
		do
		{
			cout<<"Enter name and telephone no:"<<endl;
			cin>>a;
			cin>>b;
			int k;
			char s=a[0];
			k=returnVal(s);
			hashtable p;
			strcpy(p.name,a);
			p.no=b;
			
			if(strcmp(hash[k].name,"NULL")==0)
			{
				hash[k]=p;
			}
			else
			{
				for(j=k;strcmp(hash[j].name,"NULL")!=0;j++);
				hash[j]=p;
			}
			w++;
			cout<<"do you want to add another name:"<<endl;
			cin>>m;
		}while(m!='n');
		cout<<"w="<<w<<endl;
		return w;
	}
	void display(int k)
	{
		int i;
		cout<<"telephone book database:"<<endl;
		for(i=0;i<25;i++)
		{
			if(strcmp(hash[i].name,"NULL")==0)
			{
				cout<<i<<"name:__________  number:_____________"<<endl;
			}
			else
			{
				cout<<i<<"name: "<<hash[i].name<<"        "<<"number: "<<hash[i].no<<endl;
			}
		}
	}
	void search(int k)
	{
		int q,i;
		int y=0;
		cout<<"Enter name of client:"<<endl;
		cin>>a;
		char s=a[0];
		q=returnVal(s);
		if(strcmp(hash[q].name,a)==0)
		{
			cout<<"client no is: "<<hash[q].no<<endl;
			y=1;
		}
		else
		{
			for(i=q;i<k;i++)
			{
				if(strcmp(hash[i].name,a)==0)
				{
					cout<<"client no is: "<<hash[i].no<<endl;
						y=1;
					break;
				}
			}
		}
		if(y==0)
		cout<<"client no not found!"<<endl;
		else
		cout<<"client no found succesfully!"<<endl;
	}
					
};
int main()
{
	client c;
	int o;
	o=c.insert();
	c.display(o);
	c.search(o);
	return 0;
}		
/**************OUTPUT***********************
Enter name and telephone no:
neha 123456
do you want to add another name:
y
Enter name and telephone no:
netra 234567
do you want to add another name:
y
Enter name and telephone no:
aaa 678542
do you want to add another name:
y
Enter name and telephone no:
abc 098567
do you want to add another name:
y
Enter name and telephone no:
bbb 678123
do you want to add another name:
y
Enter name and telephone no:
sss 786123
do you want to add another name:
n
w=6
telephone book database:
0name: aaa        number: 678542
1name: abc        number: 98567
2name: bbb        number: 678123
3name:__________  number:_____________
4name:__________  number:_____________
5name:__________  number:_____________
6name:__________  number:_____________
7name:__________  number:_____________
8name:__________  number:_____________
9name:__________  number:_____________
10name:__________  number:_____________
11name:__________  number:_____________
12name:__________  number:_____________
13name: neha        number: 123456
14name: netra        number: 234567
15name:__________  number:_____________
16name:__________  number:_____________
17name:__________  number:_____________
18name: sss        number: 786123
19name:__________  number:_____________
20name:__________  number:_____________
21name:__________  number:_____________
22name:__________  number:_____________
23name:__________  number:_____________
24name:__________  number:_____________
Enter name of client:
bbb
client no is: 678123
client no found succesfully!
*/
