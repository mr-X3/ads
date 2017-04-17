
#include<iostream>
#include<conio.h>
usingnamespacestd;

structnode
{
	chardt[50];                     //to store data
	structnode *lch;                //left child 
	structnode *rsb;                //right sibiling

};

structnode *root = NULL;

//function that prints content category according to level 
voidlvlname(inta)
{
	switch (a)
	{
	case 0:cout <<" Book";
		break;
	case 1:cout<<" Chapter";
		break;
	case 2:cout <<" Section";
		break;
	case 3:cout <<" Sub-Section";
		break;

	}
	
}

//function to insert nodes of tree
void insert(node *rt,intlvl)
{
	int a;
	cout<<"\nEnter no of";
	lvlname(lvl);
	cout<<"s of "<<rt->dt<<" : ";
	
	cin>>a ;

	cout<<"\n";
	for(inti=0;i<a;i++)
	{ 
		//create new node and make left, right null 
		node *tmp;     
		tmp = newnode;                    
		tmp->lch = tmp->rsb = NULL;

		//taking data input of the node 
		cout<<"Enter ";
		lvlname(lvl);
		cout<<" "<<i+1<<" name : ";
		cin>>tmp->dt;

		//if first child then store it to left child
		if ((rt->lch == NULL)&&(i==0))
		{
			
			rt->lch = tmp;

			//traverse to left child, at next level to take next childs to riht of first child
			rt = rt->lch;
		}
		else//else store to right of left child
		{
			while (rt->rsb!= NULL)    //traverse to rightmost child
				rt = rt->rsb;
			
			rt->rsb = tmp;  //store after right most child

		}
	
	}

}

//to create root node
void create()
{
	node *tmp;
	tmp = newnode;
	tmp->lch = tmp->rsb = NULL;


	if (root == NULL)
	{
		cout<<"Enter book name : ";
		cin>>tmp->dt;
		root = tmp;
	}

	insert(root, 1);  //create first level children (chapters)

}

void display(node *t,intl)
{
	
	lvlname(l);
	cout<<"s of ";
	lvlname(l - 1);
	cout<<" "<<t->dt<<" are : ";  //dispaly parent
	node *tt = t->lch;
	while (tt != NULL)
	{ //display children
		cout<<tt->dt;
		if (tt->rsb != NULL)
			cout<<" , ";
		tt = tt->rsb;
	}
cout<<"\n";

}

int main()
{
	int l = 2;
	create();
	node *tmp;
			tmp = root->lch;

		// create sections and sub-sections of chapters using dfs
		while (tmp!=NULL)
		{
			insert(tmp, l);
			node *tt = tmp->lch;
			while (tt != NULL)
			{
				insert(tt,l+1);
				tt = tt->rsb;
			}
			
			tmp = tmp->rsb;
		}

		//display tree
		cout<<"\n\n********Displaying the tree*********\n\n";

		//display book name
		display(root, 1);
		tmp = root->lch;
		//display children
		while (tmp != NULL)
		{
			cout<<"\n\n";
			display(tmp, l);
			node *tt = tmp->lch;
			while (tt != NULL)
			{//display childrens
				display(tt, l + 1);
				tt = tt->rsb;
			}

			tmp = tmp->rsb;
		}

		
	_getch();
	return 0;
}










