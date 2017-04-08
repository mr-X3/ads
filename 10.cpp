/*Assignment no:-10
Title:-Assume two input and twp output and perform sorting the internal memory and sort record into external sorting i.e(merge sort)
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/
#include <iostream>

using namespace std;
int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}
int main()
{
 int num,i;

cout<<"********************************************************";
 cout<<" \n MERGE SORT ";
 cout<<" \n Enter the no of element to be inserted : " ;
 cin>>num;
 cout<<endl;
 cout<<"  Enter the ( "<< num <<" ) numbers ";
 for(i=1;i<=num;i++)
 {
  cin>>a[i] ;
 }
 merge_sort(1,num);
 cout<<endl;
 cout<<"\n sorted list :\n ";
 for(i=1;i<=num;i++)
 cout<<a[i]<<"	";

}
------------------------------OUTPUT----------------------------------------
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop/
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ newm.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out
******************************************************** 
 MERGE SORT  
 Enter the no of element to be inserted : 5

  Enter the ( 5 ) numbers 23    56      77      32      21


 sorted list :
 21	23	32	56	77	gescoe@gescoe-OptiPlex-3010:~/Desktop$ 


 
