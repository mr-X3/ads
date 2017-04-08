/*Assignment no:-3
Title:-Convert binary tree into threaded binary tree(TBT).
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/





    #include <iostream>
    #include <cstdlib>
    #define MAX_VALUE 65536
    using namespace std;
    /* Class Node */  
    class Node
    {
    	public:
            int key;
            Node *left, *right;
            bool lbit, rbit; 
    }; 
    /* Class ThreadedBinarySearchTree */
    class ThreadedBinarySearchTree
    {
    	private:
            Node *root;
        public: 
            /* Constructor */
            ThreadedBinarySearchTree() 
            {
                root = new Node();
                root->right = root->left = root;
                root->lbit = 1;
                root->key = MAX_VALUE;
            }
            /* Function to clear tree */
            void makeEmpty()
            {
                root = new Node();
                root->right = root->left = root;
                root->lbit = 1;
                root->key = MAX_VALUE;
            }
            /* Function to insert a key */
            void insert(int key) 
            {
                Node *p = root;
                for (;;)
                {
                    if (p->key < key) 
                    {
                        if (p->rbit) 
                            break;
                        p = p->right;
                    } 
                    else if (p->key > key) 
                    {
                        if (p->lbit) 
                            break;
                        p = p->left;
                    }
                    else 
                    {
                        /* key is repeated */
                        return; 
                    }
                }
                Node *tmp = new Node();
                tmp->key = key;
                tmp->rbit = tmp->lbit = 1;
                if (p->key < key) 
                { 
                    /* insert to right side */
                    tmp->right = p->right;
                    tmp->left = p;
                    p->right = tmp;
                    p->rbit = 0;
                }
                else
                {
                    tmp->right = p;
                    tmp->left = p->left;
                    p->left = tmp;
                    p->lbit = 0;
                }
            }
            /* Function to search for an element */
            bool search(int key) 
            {
                Node *tmp = root->left;
                for (;;) 
                {
                    if (tmp->key < key) 
                    {
                        if (tmp->rbit) 
                            return 0;
                        tmp = tmp->right;
                    } 
                    else if (tmp->key > key) 
                    {
                        if (tmp->lbit) 
                            return 0;
                        tmp = tmp->left;
                    } 
                    else 
                    {
                        return 1;
                    }
                }
            }
            /* Fuction to delete an element */
            void Delete(int key)
            {
                Node *dest = root->left, *p = root;
                for (;;) 
                {
                    if (dest->key < key) 
                    {
                        /* not found */
                        if (dest->rbit) 
                            return; 
                        p = dest;
                        dest = dest->right;
                    } 
                    else if (dest->key > key) 
                    {
                        /* not found */
                        if (dest->lbit) 
                            return; 
                        p = dest;
                        dest = dest->left;
                    }
                    else 
                    {
                        /* found */
                        break; 
                    }
                }
                Node *target = dest;
                if (!dest->rbit && !dest->lbit) 
                { 
                    /* dest has two children*/
                    p = dest;
                    /* find largest node at left child */
                    target = dest->left;
                    while (!target->rbit) 
                    {
                        p = target;
                        target = target->right;
                    }
                    /* using replace mode*/
                    dest->key = target->key; 
                }
                if (p->key >= target->key) 
                {
                    if (target->rbit && target->lbit) 

                    {

                        p->left = target->left;

                        p->lbit = 1;

                    } 

                    else if (target->rbit) 

                    {

                        Node *largest = target->left;

                        while (!largest->rbit)

                        {

                            largest = largest->right;

                        }

                        largest->right = p;

                        p->left = target->left;

                    }

                    else 

                    {

                        Node *smallest = target->right;

                        while (!smallest->lbit) 

                        {

                            smallest = smallest->left;

                        }

                        smallest->left = target->left;

                        p->left = target->right;

                    }

                } 

                else 

                {

                    if (target->rbit && target->lbit) 

                    {

                        p->right = target->right;

                        p->rbit = 1;

                    }

                    else if (target->rbit) 

                    {

                        Node *largest = target->left;

                        while (!largest->rbit) 

                        {

                            largest = largest->right;

                        }

                        largest->right =  target->right;

                        p->right = target->left;

                    } 

                    else 

                    {

                        Node *smallest = target->right;

                        while (!smallest->lbit)

                        {

                            smallest = smallest->left;

                        }

                        smallest->left = p;

                        p->right = target->right;

                    }

                }

            }

     

            /* Function to print tree */

            void printTree() 

            {

                Node *tmp = root, *p;

                for (;;) 

                {

                    p = tmp;

                    tmp = tmp->right;

                    if (!p->rbit) 

                    {

                        while (!tmp->lbit) 

                        {

                            tmp = tmp->left;

                        }

                    }

                    if (tmp == root) 

                        break;

                    cout<<tmp->key<<"   ";

                }

                cout<<endl;

            }    

    };

     

    /* Main Contains Menu */

     

    int main()

    {            

        ThreadedBinarySearchTree tbst; 

        cout<<"Threaded Binary Search Tree Test\n";          

        char ch;

        int choice, val;

        /*  Perform tree operations  */

        do    

        {

            cout<<"\nThreadedBinarySearchTree Operations\n";

            cout<<"1. Insert "<<endl;

            cout<<"2. Delete"<<endl;

            cout<<"3. Search"<<endl;

            cout<<"4. Clear"<<endl; 

            cout<<"Enter Your Choice: ";

            cin>>choice;

            switch (choice)

            {

            case 1 : 

                cout<<"Enter integer element to insert: ";

                cin>>val;

                tbst.insert(val);                     

                break;                          

            case 2 : 

                cout<<"Enter integer element to delete: ";

                cin>>val;

                tbst.Delete(val);                     

                break;                         

            case 3 : 

                cout<<"Enter integer element to search: ";

                cin>>val;

                if (tbst.search(val) == 1)

                    cout<<"Element "<<val<<" found in the tree"<<endl;

                else

                    cout<<"Element "<<val<<" not found in the tree"<<endl;

                break;       

            case 4 : 

                cout<<"\nTree Cleared\n";

                tbst.makeEmpty();

                break;           

            default : 

                cout<<"Wrong Entry \n ";

                break;   

            }

            /*  Display tree  */ 

            cout<<"\nTree = ";

            tbst.printTree();            

            cout<<"\nDo you want to continue (Type y or n): ";

            cin>>ch;                       

        } 

        while (ch == 'Y'|| ch == 'y');               

        return 0;

    }

/*******output***********
archana@ubuntu:~/Desktop/Archana$ g++ tbt.cpp
archana@ubuntu:~/Desktop/Archana$ ./a.out
Threaded Binary Search Tree Test

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 1
Enter integer element to insert: 12

Tree = 12   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 1
Enter integer element to insert: 34

Tree = 12   34   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 1 
Enter integer element to insert: 67

Tree = 12   34   67   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 1
Enter integer element to insert: 10

Tree = 10   12   34   67   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 2
Enter integer element to delete: 34

Tree = 10   12   67   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 3
Enter integer element to search: 34
Element 34 not found in the tree

Tree = 10   12   67   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 3
Enter integer element to search: 12
Element 12 found in the tree

Tree = 10   12   67   

Do you want to continue (Type y or n): y

ThreadedBinarySearchTree Operations
1. Insert 
2. Delete
3. Search
4. Clear
Enter Your Choice: 4

Tree Cleared

Tree = 

Do you want to continue (Type y or n): n
*/
