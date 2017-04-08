/*Assignment no:-1
Title:-Construct the binary search tree(BST) by inserting the value in the order given after constructing a binary tree:
1.Insert new node
2.Find no. of node in largset path
3.Min data value found in the tree
4.Change the tree so that the role of left and right pointer are swap of any node
5.Search the value
Class:-SE-A
Batch:-SA-1
Roll no.:-05*/

#include<iostream>
using namespace std;

// class declaration for node
class node
{
	//public:
	
		friend class BST;
		int data;
		node *lchild;
		node *rchild;
};

//class declaration for BST operation
class BST
{
	public:
		
		node *root;
		int flag;

	//Constructor to assign root node
		BST()
		{
		root=NULL;
		}

	//Declaration of BST operation
		void insert(int key);
		void display(node *);
		int search(node *,int);
		int search1(node *,int);
		void min(node *);
		int height(node *);
		void mirror(node *);	
};

//method for inserting node in BST
void BST::insert(int key)
{
		node *newnode;
		newnode=new node();
		newnode->data=key;
		newnode->lchild=NULL;
		newnode->rchild=NULL;
		if(root==NULL)
		{
		root=newnode;
		return;
		}
		node *temp;
		temp=root;
		while(temp!=NULL)
		{
			if(temp->data==newnode->data)
			{
				cout<<"Value already exist\n";
				return;
			}
			if(newnode->data<temp->data)
			{
		// insering at left child

				if(temp->lchild==NULL)
				{
				temp->lchild=newnode;
				cout<<"Node is added Successsively on left of "<<temp->data<<"\n";
				return;
				}
				temp=temp->lchild;
			}
		else
			{ 
		//inserting at right child

				if(temp->rchild==NULL)
				{
				temp->rchild=newnode;
				cout<<"Node is added Successsively on right of "<<temp->data<<"\n";
				return;
				}
				temp=temp->rchild;			
			}
		}
}

// Displaying nodes of tree using inorder traversal

void BST::display(node *temp)
{

	if(temp!=NULL)
	{
	display(temp->lchild);
	cout<<"\t"<<temp->data;
	display(temp->rchild);
	}
}

//method for finding minimum node element in BST
void BST::min(node *temp)
{
	if(temp!=NULL)
	{
		while(temp->lchild!=NULL)
		{
			temp=temp->lchild;
		}
		cout<<"\tMinimum node in tree :"<<temp->data;
	}
}

//recursive method for searching node element in BST 

int BST::search(node *temp,int key)
{

	if(temp!=NULL)
	{
	search(temp->lchild,key);
	if(temp->data==key)
	{
	flag=1;
		}	
	search(temp->rchild,key);
	}
	
}

//non-recursive method for searching node element in BST 

int BST::search1(node *temp,int key)
{
	if(temp==NULL)
	cout<<"Tree is empty\n";
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				return 1;
			}
			else
			if(temp->data<key)
			{
				temp=temp->rchild;
			}	
			else
			{
				temp=temp->lchild;
			}
		}
		return 0;
	}
	
}

//Method for finding height of BST and Maximum number in longest path of BST

int BST::height(node *temp)
{
	int l=0,r=0;
	if(temp!=NULL)
	{

		l=height(temp->lchild);
		r=height(temp->rchild);
	}
	if(l>r)
	return l+1;
	else 
	return r+1;
}

//method for exchanging for left & right chid of BST
	
void BST::mirror(node *temp)
{
	node *temp1;
	if(temp!=NULL)
	{
	temp1=temp->lchild;
	temp->lchild=temp->rchild;
	temp->rchild=temp1;
	mirror(temp->lchild);
	mirror(temp->rchild);
	}	
}




int main()
{
	BST b;
	int ch,key;
	do
	{
		cout<<"\n---------------------------------\n";
		cout<<"\tOperation on BST\t\n";
		cout<<"---------------------------------\n";
		cout<<"1.Insert a node\n";
		cout<<"2.Display a BST\n";
		cout<<"3.Search a node with recursive method\n4.Find MINIMUM\n5.SEARCH using non-recursive method\n";
		cout<<"6:Find Height\n7:Mirror \n8:Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:  
					//insertion of node
					cout<<"Enter a data to be enter into node\n";
					cin>>key;
					b.insert(key);
					break;
			case 2:
					//Displaying nodes
					cout<<"\nDisplay in Inorder Traversal :\n";
					 b.display(b.root);
					break;
			case 3: 
					//searching element
					cout<<"\tEnter data to be search\n";
					cin>>key;
					b.flag=0;
					b.search(b.root,key);
					if(b.flag==1)
					cout<<"\tData Found\n";
					else
					cout<<"\tData not Found\n"; 
					break;
			case 4: 
					//find minimum node
					b.min(b.root);
					break;
			case 5:
					//searching element using non-recursive
					cout<<"\tEnter data to be search\n";
					cin>>key;
					b.flag=b.search1(b.root,key);
					if(b.flag==1)
					cout<<"\tData Found\n";
					else
					cout<<"\tData not Found\n"; 
					break;
			case 6 :
					//finding height of BST
					b.flag=b.height(b.root);
					cout<<"Height of BST:"<<b.flag-1;
					cout<<" \nNumber nodes in longest path :"<<b.flag;
					cout<<"\n";
					break;
			case 7 :	
					//exchanging for left & right chid of BST
					b.mirror(b.root);
					b.display(b.root);
					break;
			case 8 :
					 return 0;
		}
	}while(1);
		return 0;
}




	
----------------------------------------OUTPUT:---------------------------------------------------------
GESCOE@ubuntu:~$ cd Desktop
GESCOE@ubuntu:~/Desktop$ cd GESCOE
GESCOE@ubuntu:~/Desktop/GESCOE$ g++ bst2.cpp
GESCOE@ubuntu:~/Desktop/GESCOE$ ./a.out

 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 1

Enter the number of Nodes to be inserted : 4

 Enter the element to insert : 12

 Enter the element to insert : 34

 Enter the element to insert : 25

 Enter the element to insert : 10

 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 3

 1.Preorder
 2.Inorder
 3.Postorer
 Enter your choice : 1

Preorder Display of Entered Nodes
  50
   12
   10
   34
   25
 
 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 3

 1.Preorder
 2.Inorder
 3.Postorer
 Enter your choice : 2

Inorder Display of Entered Nodes
  10
   12
   25
   34
   50
 
 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 3

 1.Preorder
 2.Inorder
 3.Postorer
 Enter your choice : 3

Postorder Display of Entered Nodes
   10
   25
   34
   12
   50
 
 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 2
Enter key to search : 12
Key Found = 12	 Location : 0x80a4008
Key found in tree

 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 4
TREE is SWAPPED....	
 1.Insertion
 2.Search
 3.Display { 1.Preorder. 2.Inorder. 3.Postorder. }
 4.Swap
 5.Height of tree
 Enter your choice : 5
Height of tree is : 4
/*
GESCOE@ubuntu:~/Desktop/GESCOE$ 
*/
