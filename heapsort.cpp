#include<iostream>
#include<conio.h>
usingnamespacestd;

// function to max heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
voidheapify(intarr[], intn, inti)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

	// If left child is larger than root
	if (l <n&&arr[l] >arr[largest])
		largest = l;

	// If right child is larger than current largest
	if (r <n&&arr[r] >arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
voidheapSort(intarr[], intn)
{
	// Build heap (rearrange array)
	for (inti = n / 2 - 1; i>= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (inti = n - 1; i>= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

//function to print array of size n
voidprintArray(intarr[], intn)
{
	cout<<"\n\nHighest score is "<<arr[n-1] <<"\nMinimum score is : "<<arr[0];
	cout<<"\n\nMarks in sorted order are \n";
	for (inti = 0; i<n; ++i)
	{
		cout<<arr[i];
		if ((i + 1) <n)
			cout<<",";
	}
}


int main()
{
	cout<<"===========HEAP SORT===========\n";
	intn,arr[20];
	cout<<"How many students : ";
	cin>> n;
	for (inti = 0; i< n; i++)
	{
		cout<<"Enter marks of student "<< i+1 <<" : ";
		cin>>arr[i];
	}
	heapSort(arr, n);

	printArray(arr, n);
	_getch();
	return 0;
}
