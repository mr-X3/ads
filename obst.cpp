

#include<iostream>
#include<stdlib.h>
#include<string>
#defineMAX 20
usingnamespace std;


typedefstructOBST
{
	string KEY;
	structOBST *left, *right;
}
OBST;


int C[MAX][MAX]; //cost matrix
int W[MAX][MAX]; //weight matrix
int R[MAX][MAX]; //root matrix
int q[MAX]; //unsuccesful searches
int p[MAX]; //frequencies
int n; //number of keys in the tree
string KEYS[MAX];

OBST *ROOT=NULL;

void calculate_wcr()
{
	int x, min;
	int i, j, k, h, m;
	//Construct weight matrix W
	for (i = 0; i <= n; i++)
	{
		W[i][i] = q[i];
		for (j = i + 1; j <= n; j++)
			W[i][j] = W[i][j - 1] + p[j] + q[j];
	}
	//Construct cost matrix C and root matrix R
	for (i = 0; i <= n; i++)
		C[i][i] = 0;
	for (i = 0; i <= n - 1; i++)
	{
		j = i + 1;
		C[i][j] = C[i][i] + C[j][j] + W[i][j];
		R[i][j] = j;
	}
	for (h = 2; h <= n; h++)
		for (i = 0; i <= n - h; i++)
		{
			j = i + h;
			m = R[i][j - 1];
			min = C[i][m - 1] + C[m][j];
			for (k = m + 1; k <= R[i + 1][j]; k++)
			{
				x = C[i][k - 1] + C[k][j];
				if (x < min)
				{
					m = k;
					min = x;
				}
			}
			C[i][j] = W[i][j] + min;
			R[i][j] = m;
		}
		//Display weight matrix W
		cout<<"\nThe weight matrix W:\n";
		for (int k = 0; k <=n; k++)
		{
			for (i = 0; i <=n; i++)
			{
				for (j = 0; j <=n; j++)
					if((j-i)==k)
					  cout << W[i][j] <<" ";
			}
			cout <<"\n";
		}

	//Display Cost matrix C
	cout<<"\nThe cost matrix C:\n";
	for (int i = 0; i <= n; i++)
		C[i][i] = 0;
	for (int k = 0; k <= n; k++)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
				if ((j - i) == k)
					cout << C[i][j] <<" ";
		}
		cout <<"\n";
	}

	//Display root matrix R
	cout<<"\nThe root matrix R:\n";
	for (int k = 0; k <= n; k++)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
				if ((j - i) == k)
					cout << R[i][j] <<" ";
		}
		cout <<"\n";
	}
}
//Construct the optimal binary search tree
OBST *CONSTRUCT_OBST(inti, intj)
{
	OBST *p;
	if (i == j)
		p = NULL;
	else
	{
		p = newOBST;
		p->KEY = KEYS[R[i][j]];
		p->left = CONSTRUCT_OBST(i, R[i][j] - 1); //left subtree
		p->right = CONSTRUCT_OBST(R[i][j], j); //right subtree
	}
	return p;
}
//Display the optimal binary search tree
void DISPLAY(OBST *ROOT, intl)
{
	int i;
	if (ROOT != 0)
	{
		DISPLAY(ROOT->right, l + 1);
		for (i = 0; i <= l; i++)
			cout <<"   ";;
		cout <<ROOT->KEY <<"\n";
		DISPLAY(ROOT->left, l + 1);
		}
}
void OPTIMAL_BINARY_SEARCH_TREE()
{
	float avg;

	calculate_wcr();
	cout <<"\nC[0] = "<< C[0][n] <<" W[0] = "<< W[0][n] <<"\n";
	avg =C[0][n]/ (float)W[0][n];
	cout<<"The cost per weight ratio is : "<<avg<<"\n\n";
	ROOT = CONSTRUCT_OBST(0, n);
}

int main()
{
	int i, ch;

	cout<<"How many keys : ";
	cin>>n;

	for (i = 1; i <=n; i++)
	{
		cout<<"key["<<i<<"] = ";
	    cin>>KEYS[i];
		cout <<"Frequency of "<< KEYS[i]<<" = ";
		cin >> p[i];
	}

	for (i = 0; i <= n; i++)
	{
		cout<<"q["<<i<<"] = ";
		cin >> q[i];
	}
	while (1)
	{
		cout<<"\n1.Construct tree\n2.Display tree\n3.Exit\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			OPTIMAL_BINARY_SEARCH_TREE();
			break;
		case 2:
			if (ROOT == NULL)
				cout <<"No tree created\nFirst create tree\n";
			else
			{
				cout <<"\n\nDisplaying the tree\n";
				DISPLAY(ROOT, 0);
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
	system("PAUSE");
}





