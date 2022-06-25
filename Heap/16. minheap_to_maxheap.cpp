// A C++ program to convert min Heap to max Heap
#include<bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void heapify(int arr[], int i, int n)
{
	int largest=i;
    int lc=2*i+1;
    int rc=2*i+2;
    if(lc<n&&arr[largest]<arr[lc])
        largest=lc;
    if(rc<n&&arr[largest]<arr[rc])
        largest=rc;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}

// This function basically builds max heap
void buildHeap(int arr[], int n)
{
    int startIndex=n/2-1;
    for(int i=startIndex;i>=0;i--)
        heapify(arr,i, n);
}

// A utility function to print a given array
// of given size
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
	// array representing Min Heap
	int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Min Heap array : ");
	printArray(arr, n);

	buildHeap(arr, n);

	printf("\nMax Heap array : ");
	printArray(arr, n);

	return 0;
}
