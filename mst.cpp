
#include<iostream>
#include<stdlib.h>
using namespace std;
inti,j,k,a,b,u,v,n,ne=1;
intminn,mincost=0,cost[9][9],parent[9];
int find(int);
intuni(int,int);
int main()
{

 cout<<"\n\n\tImplementation of Kruskal's algorithm\n\n";
 cout<<"\nEnter the no. of vertices\n";
 cin>>n;
 cout<<"\nEnter the cost adjacency matrix\n";
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   cin>>cost[i][j];
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
 cout<<"\nThe edges of Minimum Cost Spanning Tree are\n\n";
 while(ne<n)
 {
    minn=999;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<minn)
    {
     minn=cost[i][j];
     a=u=i;
     b=v=j;
    }
   }
  }
  u=find(u);
  v=find(v);
  if(uni(u,v))
  {
   cout<<endl<<ne++<<"  edge ("<<a<<" , "<<b<<"=\n"<<minn;
   mincost +=minn;
.  }
  cost[a][b]=cost[b][a]=999;
 }
 cout<<"\n\tminnimum cost = \n"<<mincost;

}
int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
intuni(inti,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}


