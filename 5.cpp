/*Assignment no:-5
Title:-You have a business write several office you want to lease phone line of connect them up with each other and the phone company  change different amount of many of connecting
different pairs of cties you want to set a line that connect all your office with min total cost.Solve the problem by suggesting appropriate data structure.
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/
//Program to implement kruskcal algorithm
#include <iostream>
#include <fstream>

using namespace std;

class kruskal
{
    private:
    int n; //no of nodes
    int noe; //no edges in the graph
    int graph_edge[100][4];

    int tree[10][10];

    int sets[100][10];
    int top[100];
    public:
    int read_graph();
    void initialize_span_t();
    void sort_edges();
    void algorithm();
    int find_node(int );
    void print_min_span_t();
};

int kruskal::read_graph()
{
cout<<"This program implements the kruskal algorithm\n";
cout<<"Enter the no. of nodes in the undirected weighted graph";
cin>>n;
noe=0;

cout<<"Enter the weights for the following edges ::\n";

for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
        cout<<i<<" , "<<j;
        int w;
        cin>>w;
            if(w!=0)
            {
            noe++;

            graph_edge[noe][1]=i;
            graph_edge[noe][2]=j;
            graph_edge[noe][3]=w;
            }
        }
    }

// print the graph edges

cout<<"\n\nThe edges in the given graph are::\n";
for(int i=1;i<=noe;i++)
{
    cout<<" < "<<graph_edge[i][1]
    <<" , "<<graph_edge[i][2]
    <<" > "<<graph_edge[i][3]<<endl;

}
}

void kruskal::sort_edges()
{
/**** Sort the edges using bubble sort in increasing order**************/

for(int i=1;i<=noe-1;i++)
{
    for(int j=1;j<=noe-i;j++)
    {
        if(graph_edge[j][3]>graph_edge[j+1][3])
        {
        int t=graph_edge[j][1];
        graph_edge[j][1]=graph_edge[j+1][1];
        graph_edge[j+1][1]=t;

        t=graph_edge[j][2];
        graph_edge[j][2]=graph_edge[j+1][2];
        graph_edge[j+1][2]=t;

        t=graph_edge[j][3];
        graph_edge[j][3]=graph_edge[j+1][3];
        graph_edge[j+1][3]=t;
        }
    }
}

// print the graph edges

cout<<"\n\nAfter sorting the edges in the given graph are::\n";
for(int i=1;i<=noe;i++)
cout<<""<< graph_edge[i][1]
<<" , "<<graph_edge[i][2]
<<" > ::"<<graph_edge[i][3]<<endl;
}

void kruskal::algorithm()
{
    // ->make a set for each node
    for(int i=1;i<=n;i++)
    {
    sets[i][1]=i;
    top[i]=1;
    }

cout<<"\nThe algorithm starts ::\n\n";

    for(int i=1;i<=noe;i++)
    {
    int p1=find_node(graph_edge[i][1]);
    int p2=find_node(graph_edge[i][2]);

        if(p1!=p2)
        {
            cout<<"The edge included in the tree is ::"
            <<" < "<<graph_edge[i][1]<<" , "
            <<graph_edge[i][2]<<" > "<<endl<<endl;

            tree[graph_edge[i][1]][graph_edge[i][2]]=graph_edge[i][3];
            tree[graph_edge[i][2]][graph_edge[i][1]]=graph_edge[i][3];

            // Mix the two sets

            for(int j=1;j<=top[p2];j++)
            {
                top[p1]++;
                sets[p1][top[p1]]=sets[p2][j];
            }

            top[p2]=0;
        }
        else
        {
            cout<<"Inclusion of the edge "
            <<" < "<<graph_edge[i][1]<<" , "
            <<graph_edge[i][2]<<" > "<<"forms a cycle so it is removed\n\n";
        }
    }
}

int kruskal::find_node(int n)
{
    for(int i=1;i<=noe;i++)
    {
        for(int j=1;j<=top[i];j++)
        {
        if(n==sets[i][j])
            return i;
        }
    }

    return -1;
}

void kruskal::print_min_span_t()
{
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
cout<<tree[i][j]<<"\t";
cout<<endl;
}
}

int main()
{
    kruskal obj;
    obj.read_graph();
    obj.sort_edges();
    obj.algorithm();
    obj.print_min_span_t();
    return 0;
}

OUTPUT:-
gesoe@gesoe-OptiPlex-3010:~/Desktop$ g++ krusk.cpp
gesoe@gesoe-OptiPlex-3010:~/Desktop$ ./a.out
This program implements the kruskal algorithm
Enter the no. of nodes in the undirected weighted graph 4
Enter the weights for the following edges ::
1 , 2 3
1 , 3 2
1 , 4 6
2 , 3 5
2 , 4 1
3 , 4 4


The edges in the given graph are::
 < 1 , 2 > 3
 < 1 , 3 > 2
 < 1 , 4 > 6
 < 2 , 3 > 5
 < 2 , 4 > 1
 < 3 , 4 > 4


After sorting the edges in the given graph are::
2 , 4 > ::1
1 , 3 > ::2
1 , 2 > ::3
3 , 4 > ::4
2 , 3 > ::5
1 , 4 > ::6

The algorithm starts ::

The edge included in the tree is :: < 2 , 4 > 

The edge included in the tree is :: < 1 , 3 > 

The edge included in the tree is :: < 1 , 2 > 

Inclusion of the edge  < 3 , 4 > forms a cycle so it is removed

Inclusion of the edge  < 2 , 3 > forms a cycle so it is removed

Inclusion of the edge  < 1 , 4 > forms a cycle so it is removed

0	3	2	0	
3	0	0	1	
2	0	0	0	
0	1	0	0	
*/
