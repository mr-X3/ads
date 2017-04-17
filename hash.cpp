Code:
#include<iostream>
#include<math.h>
usingnamespace std;
constint max  = 10;

class Hash
{
public:
	int key;
	longlongint value;
	Hash(int key, longlongint value)
	{
		this->key = key;
		this->value = value;
	}
};

Class hashmapping
{
private:
	Hash **table;
public:
	
	hashmapping()
	{
		table = new Hash *[max];
		for (int i = 0; i< max; i++)
		{
			table[i] = NULL;
		}
	}
	
	int hashfn(int key)
	{
		Return key % max;
	}
	
	void Insert(int key, longlongint value)
	{
		int hash = hashfn(key);
		while (table[hash] != NULL&& table[hash]->key != key)
		{
			hash = hashfn(hash + 1);
		}
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new Hash(key, value);
	}
	
	int Search(int key)
	{
		int hash = hashfn(key);
		while (table[hash] != NULL&& table[hash]->key != key)
		{
			hash = hashfn(hash + 1);
		}
		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->value;
	}

	void Remove(int key)
	{
		int hash = hashfn(key);
		while (table[hash] != NULL)
		{
			if (table[hash]->key == key)
				break;
			hash = hashfn(hash + 1);
		}
		if (table[hash] == NULL)
		{
			cout <<"\n\tNo Element found at key "<<key<<"\n";
			return;
		}
		else
		{
			delete table[hash];
		}
		cout <<"\n\tElement Deleted"<< endl;
	}
	
	void display()
	{
		cout <<"\nIndex \tKeys \tValues\n";
		for(int i=0;i<max;i++)
		if(table[i]!=NULL)
		cout <<"\n "<<i<<" \t"<< table[i]->key <<"\t"<< table[i]->value;
	}
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL)
				delete table[i];
			delete[] table;	
		}
	}
};

int main()
{
	hashmapping hash;
	int key,n;
	longlongint value;
	int ch;
	cout <<"How many clients : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{   
		cout << i+1<<" Enter client id : ";
		cin >> key;
		cout <<"Enter contact number : ";
		cin >> value;
		hash.Insert(key, value);
	}
	while (1)
	{
		cout <<"\n1.Add contact\n2.Search contact from the client id\n";
		cout<<"3.Delete contact from client id\n4.Display the table\n5.Exit\n";
		cout <<"Enter your choice : ";
		cin >> ch;
		cout <<"\n";
		switch (ch)
		{
		case 1:
			cout <<"Enter client id : ";
			cin >> key;
			cout <<"Enter contact number : ";
			cin >> value;
			hash.Insert(key, value);
			break;
		case 2:
			cout <<"\nEnter id of client to be searched: ";
			cin >> key;
			if (hash.Search(key) == -1)
			{
				cout <<"\n\tNo client found at id : "<< key << endl;
				continue;
			}
			else
			{
				cout <<"\nContact number of client with id="<< key <<" is : "<< hash.Search(key) <<"\n";
			}
			break;
		case 3: cout <<"\nEnter id of the client to be deleted: ";
			cin >> key;
			hash.Remove(key);
			break;
		case 4:hash.display();
			break;
		case 5: exit(0);
			break;
			
		default:
			cout <<"\nPlease Enter correct option\n";
		}
	}
	return 0;
}

