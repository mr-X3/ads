/*
ASSIGNMENT NO:D-18
Title:Given sequence k = k1 <k2 < ... < kn of n sorted keys, with a search probability pi for each
key ki . Build the Binary search tree that has the least search cost given the access probability
for each key
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/
#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 10
void con_obst(void);
void print(int,int);
int p[MAX],q[MAX],w[10][10],c[10][10],r[10][10],i,j,k,n,m;
char idnt[7][10];

int main()
{
	cout<<"enter the no, of identifiers";
	cin>>n;
	cout<<"enter identifiers \n";
	for(i=1;i<=n;i++)
	cin>>idnt[i];

	cout <<"enter success probability for identifiers \n";
	for(i=1;i<=n;i++)
		cin >>p[i];
	cout << "enter failure probability for identifiers \n";
	for(i=0;i<=n;i++)
	{
		cin >> q[i];
	}
	con_obst();
	      print(0,n);
	      cout<<endl;
}
void con_obst(void)
{
      int i,j,l;
      for(i=0;i<n;i++)
      { //Initialisation
            c[i][i]=0.0;
            r[i][i]=0;
            w[i][i]=q[i];
         // for j-i=1 c n q j=i+1
            w[i][i+1]=q[i]+q[i+1]+p[i+1];
            c[i][i+1]=q[i]+q[i+1]+p[i+1];
            r[i][i+1]=i+1;
      }
      c[n][n]=0.0;
      r[n][n]=0;
      w[n][n]=q[n];
      //for j-i=2,3,4.,n
      for(i=2;i<=n;i++)
      {
            for(j=0;j<=n-i;j++)
            {
                  w[j][j+i]=q[j+i]+p[j+i]+w[j][j+i-1];
                  c[j][j+i]=9999;
                  for(l=j+1;l<=j+i;l++)
                  {
                        if(c[j][j+i]>(c[j][l-1]+c[l][j+i]))
                        {
                              c[j][j+i]=c[j][l-1]+c[l][j+i];
                              r[j][j+i]=l;
                        }
                  }
                  c[j][j+i]+=w[j][j+i];
            }
            cout<<endl;
      }
      cout<<"\n\nOptimal BST is :: ";
      cout<<"\nw[0]["<<n<<"] :: "<<w[0][n];
      cout<<"\nc[0]["<<n<<"] :: "<<c[0][n];
      cout<<"\nr[0]["<<n<<"] :: "<<r[0][n];
}


void print(int i,int j)
{

if(i<j)
cout<<"\n"<<idnt[r[i][j]];
else
return;
print(i,r[i][j]-1);
print(r[i][j],j);
}
/*OUTPUT

enter the no, of identifiers4
enter identifiers
do
if
int
while
enter success probability for identifiers
3
3
1
1
enter failure probability for identifiers
2
3
1
1
1

Optimal BST is ::
w[0][4] :: 16
c[0][4] :: 32
r[0][4] :: 2
if
do
int
while


*/
