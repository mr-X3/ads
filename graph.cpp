#include<iostream>
#define max 10
using namespace std;


struct node
{
int vertex;
struct node *next;
};

struct node *head[10];



 void create_list(int m)
  {
   int v1,v2;

   node *n,*tmp;
 for(int i=0;i<m;i++)
  {
      cout<<"\nEnter the vertices of edge : ";
       cin>>v1>>v2;
        if(v1>=max||v2>=max)
    {
      cout<<"\nInvalid\n";
    }
      else
    {
    n=new node;
    n->vertex=v2;
    n->next=NULL;
    tmp=head[v1];
    if(tmp==NULL)
    head[v1]=n;
    else
    {
        while(tmp->next!=NULL)
             tmp=tmp->next;

                tmp->next=n;

    }
    n=new node;
    n->vertex=v1;
    tmp=head[v2];
    if(tmp==NULL)
    head[v2]=n;
    else
    {
        while(tmp->next!=NULL)
          tmp=tmp->next;

                tmp->next=n;
    }
    }
 }

}

void display(node *gr)
{ if(gr!=NULL)
   {
     cout<<gr->vertex<<"  ";
     display(gr->next);
   }
}

 void create_matrix(int n)
  {  int a[max][max],v1,v2;

   for(int i=0;i<max;i++)
      for(int j=0;j<max;j++)
          a[i][j]=0;
   for(int i=0;i<n;i++)
  {
      cout<<"\nEnter the vertices of edge : ";
       cin>>v1>>v2;
        if(v1>=max||v2>=max)
    {
      cout<<"\nInvalid\n";

    }
      else
    {
         a[v1][v2]=a[v2][v1]=1;
    }      
  }
for(int i=0;i<n;i++)
   {   cout<<"\n\t";
       for(int j=0;j<n;j++)
          cout<<a[i][j]<<"\t";
   }

}
int main()
{
  int i,n,ch=0;
  for(i=0;i<max;i++)
   head[i]=NULL;
 while(ch!=3)
{
   cout<<"1 Adjacency list\n2 Adjacency matrix\n3 Exit\nEnter choice : ";
   cin>>ch;
   cout<<"\nHow many nodes : ";
   cin>>n;
 if(ch==1)
 {
  create_list(n);
  cout<<"\nDisplaying the graph in adjacency linklist \n";
  for(i=1;i<=n;i++)
    {  if(head[i]!=NULL)
      {
        cout<<"\nHEAD["<<i<<"]--> : ";
        display(head[i]);
      } 
    }
  cout<<"\n\n";
 }

 if(ch==2)
  {

 create_matrix(n); 

  }
 }
}


