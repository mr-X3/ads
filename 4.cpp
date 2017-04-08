//Assignment no:-4
/*Title:-Write a function to perform to get the no. of vertices in an undirected graph and its edges you assume that no edges is input twice.(Using Adjacency List and Adjacency Matrix)
Class:-SE-A
Batch:-SA-4
Roll no.:-64
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
          public:
					int data;
					node *next;
};

class graph
{
	int max;
	int a[10][10],n;
	public:
		int cnt,acnt;
		node *head[10];
		node *t;
	
		void input_linklist();
              void display();
		static int time;
		void read_node();
		void display_matrix();
};

int graph::time=0;

void graph::input_linklist()
{
	cout<<"\nEnter the Number of node";
	 cin>>cnt;
	 node *temp;
        for(int i=1;i<=cnt;i++)
	 {
		 head[i]=new node();
               cout<<"\nEnter the Head  "<<i<<" data";
               cin>>head[i]->data;
               cout<<"\nEnter the no of element to be attach";
		 cin>>acnt;
		 temp=head[i];
		 for(int j=1; j<=acnt; j++)
		{
			t=new node();
			t->next=NULL;
			cout<<"\nEnter the Element to be attach to"<<head[i]->data<<":";
			cin>>t->data;
                     temp->next=t;
			temp=temp->next;													
	      }	
      }	
}

void graph::display()
{
	 for(int i=1;i<=cnt;i++)
	 {
         	t=head[i];
              while(t!=NULL)
		{
               	cout<<t->data<<"->";
			t=t->next;
	 	}
		cout<<"NULL";
              cout<<"\n";             
	}								
}

void graph::read_node()
{
	cout<<"Enter number of nodes n graph\n";
	time++;
	cin>>n;
	time++;
	cout<<"Enter 1 if edge is present between nodes else enter 0\n";
	time++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"Is edge from "<<i<<"->"<<j<<"\n";
			time++;
			cin>>a[i][j];
			time++;
		}
	}
}
void graph::display_matrix()
{
	cout<<"Adjacency matrix of given graph\n";
	time++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"\t";
			time++;
		}
		cout<<endl;
		time++;
	}
}
int main()
{
	graph g;
	int ch;
       while(1)
	{
        	cout<<"\n1.List insert";
		cout<<"\n2.List display";
              cout<<"\n3.Matrix read";
              cout<<"\n4.Matrix display";
              cout<<"\n5.Exit";
              cout<<"\nEnter the choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
                               g.input_linklist();
				   break;
			case 2:
				   g.display();
				   break;
                     case 3:
                              g.read_node();
				   break;
                     case 4:
				g.display_matrix();
				 break;
                      case 5:
                               exit(0);	 
		}
       }
	cout<<"Total time require ::"<<graph::time<<endl;
}
------------------------------------------OUTPUT------------------------------------------------------------
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ matrix.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice1

Enter the Number of node3

Enter the Head  1 data65

Enter the no of element to be attach4

Enter the Element to be attach to65:33

Enter the Element to be attach to65:78

Enter the Element to be attach to65:21

Enter the Element to be attach to65:45

Enter the Head  2 data50

Enter the no of element to be attach2

Enter the Element to be attach to50:36

Enter the Element to be attach to50:55

Enter the Head  3 data2

Enter the no of element to be attach2

Enter the Element to be attach to2:1

Enter the Element to be attach to2:4

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice2
65->33->78->21->45->NULL
50->36->55->NULL
2->1->4->NULL

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice4
Adjacency matrix of given graph

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice3
Enter number of nodes n graph
3
Enter 1 if edge is present between nodes else enter 0
Is edge from 1->1
1
Is edge from 1->2
3
Is edge from 1->3
5
Is edge from 2->1
6
Is edge from 2->2
7
Is edge from 2->3
1
Is edge from 3->1
2
Is edge from 3->2
3
Is edge from 3->3
4

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice4
Adjacency matrix of given graph
1	3	5	
6	7	1	
2	3	4	

1.List insert
2.List display
3.Matrix read
4.Matrix display
5.Exit
Enter the choice5
gescoe@gescoe-OptiPlex-3010:~/Desktop$ 

