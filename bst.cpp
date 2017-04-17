
#include<iostream>
usingnamespacestd;

//structure for binary tree
structnode
{
	int data;
	structnode *left;
	structnode *right;
};

//declaring root and temporary nodes
structnode *temp, *p, *root = NULL;

//insert function for new node 
void insert(node *root, node *p)
{   //less than root then traverse to left
	if (p->data <= root->data)
	{
		if (root->left == NULL)
			root->left = p;
		else
			insert(root->left, p);

	}
	else//else traverse to right
	{
		if (root->right == NULL)
			root->right = p;
		else
			insert(root->right, p);

	}
}

//function to initiate binary tree 
void create()
{
	int a[20], n;
	cout<<"Create the binary search tree\nEnter no of elements of tree : ";
	cin>> n;
	cout<<"\nEnter "<< n <<" elements : ";
	for (int i = 0; i < n; i++)
		cin>> a[i];
	//first element as root
	if (root == NULL)
	{
		node *p;
		p = newnode;
		p->data = a[0];
		root = p;
		p->left = NULL;
		p->right = NULL;
	}

	//remaining elements stored to next levels
	for (int i = 1; i < n; i++)
	{
		node *p;
		p = newnode;
		p->data = a[i];
		p->left = NULL;
		p->right = NULL;
		insert(root, p);
	}
	cout<<"\nBinary Search Tree created\n";
}

//function to display bst (inorder sequence)
voiddisp(node *root)
{
	if (root != NULL)
	{
		cout<<root->data <<"\t";
		disp(root->left);
		disp(root->right);
	}

	
}

//function to find least node
void least(node *root)
{
	node *temp = root;
	int m = root->data;  //root assumed to be minimum

	//minimum of left subtree updated in m
	while (root != NULL)
	{
		if (root->data < m)
			m = root->data;
		root = root->left;
	}

	//minimum of right subtree updated in m
	while (temp != NULL)
	{
		if (temp->data < m)
			m = temp->data;
		temp = temp->right;
	}
	cout<<"\nLeast node value is : "<< m <<"\n\n";
}

//function to find depth
int depth(node *root)
{

	int d1, d2;
	if (root == NULL) //empty tree
		return -1;
	if ((root->left == NULL) && (root->right == NULL))//only root present
		return 0;
	d1 = depth(root->left); //depth of left subtree
	d2 = depth(root->right);  //depth of right subtree
	
	//return max depth among left and right
	if (d1 > d2)
		return ++d1;
	else
		return ++d2;
}

//function for mirror imaging the tree
void  mirror(node *root)
{
	if (root != NULL)
	{
		mirror(root->left);
		mirror(root->right);
//swap left and right nodes
		p = root->left;
		root->left = root->right;
		root->right = p;
	}
}

//function to search key
void search(node *root, intkey)
{
	if (root == NULL)
	{
		cout<<"\nNo tree created\n";
		return;
	}
	int f = 0;
	while (root != NULL)
	{
		if (root->data == key)
		{
			f = 1;
			cout<<"\n"<<root->data <<" is Present\n\n";
			break;
		}
		if (key<root->data) //key is less than root then search to left
			root = root->left;
		else
			root = root->right; //else search to right
	}
	if (f == 0)
		cout<<"\n"<<key<<" is not present\n\n";
}



int main()
{
	create();

	intch, key;
	do
	{  
		cout<<"\n\n1:Insert new node\n2:Display\n3:Height\n4:Mirror\n5:Nodes in longest path\n6:Search\n7:Least value in the tree\n8:Exit\nEnter choice : ";
		cin>>ch;
		
		switch (ch)
		{
		case 1:node *p;  //create new node and call insert
			p = newnode;
			cout<<"Enter newnode data : ";
			cin>> p->data;
			p->left = NULL;
			p->right = NULL;
			insert(root, p);
			break;
		
		case 2:cout <<"\n";
			disp(root);
			cout<<"\n\n";
			break;
		
		case 3:cout <<"\nHeight is : "<< depth(root) + 1;
			break;
		
		case 4:cout <<"\n";
			mirror(root);
			disp(root); //display after mirror imaging
			charch;
			cout<<"\nReverse tree back to original Yes(Y)/No(N) : ";
			cin>>ch;
			if((ch=='y')||(ch=='Y'))
			mirror(root);//arranging tree to original
			break;
		
		case 5: cout<<"\nLongest path has "<< depth(root) + 1 <<" nodes\n";
			break;
		
		case 6:cout <<"\nEnter data to be searched : ";
			cin>> key;
			search(root, key);
			break;
		
		case 7:least(root);
			break;
		
		default:cout<<"\n Invalid choice\n";
		
		}
	} while (ch != 8); // exit if choice is 8
	
	return 0;
}





