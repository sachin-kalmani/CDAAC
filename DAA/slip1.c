//Write programs in C/C++/ Java to sort a list of n numbers in ascending order using
//selection sort, insertion sort, heap sort, radix sort. Determine the time required to sort
//and compare on basis of time complexity for different values of n
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>

//selection sort
void selectionSort(int arr[],int n)
{
	int arr2[n];
	int i,pos,temp,m;
	copyArray(arr,arr2,n);
	for(pos=0;pos<n-1;pos++)
	{
		m=pos;
		for(i=pos+1;i<n;i++)
		{
			if(arr2[i]<arr2[m])
				m=i;
		}
		temp=arr2[pos];
		arr2[pos]=arr2[m];
		arr2[m]=temp;
	}
	
	printArray(arr2,n);
}

//insertion sort
void insertionSort(int arr[],int n)
{
	int arr3[n];
	int i,k,key;
	copyArray(arr,arr3,n);
	for(k=0;k<n;k++)
	{
		key=arr3[k];
		for(i=k-1;arr3[i]>key && i>=0;i--)
		{
			arr3[i+1]=arr3[i];
		}
		arr3[i+1]=key;
	}
	printArray(arr3,n);
}

void heapify(int arr[], int n, int i) {

    // Initialize largest as root
    int largest = i; 

    // left index = 2*i + 1
    int l = 2 * i + 1; 

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
//heap sort
void heapSort(int arr[],int n)
{
	int arr4[n];
	copyArray(arr,arr4,n);
	int i;
	// Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr4, n, i);
    }

    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--) {

        // Move current root to end
        int temp = arr4[0]; 
        arr4[0] = arr4[i];
        arr4[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr4, i, 0);
    }
    printArray(arr4,n);
}


//radix sort
int getMax(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array as 0
	int i;
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now 
    // contains actual position of this digit
    // in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], 
    // so that arr[] now contains sorted 
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
  
    // Find the maximum number to know 
    // the number of digits
    int arr5[n];
    copyArray(arr,arr5,n);
    int m = getMax(arr5, n); 
	int exp;
    // Do counting sort for every digit
    // exp is 10^i where i is the current 
    // digit number
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr5, n, exp);
}


//display array
void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n"); 
}

void copyArray(int arr[],int array2[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		array2[i]=arr[i];
	}
}

void main(){
	int array[]={11,23,55,1,3,12,45,21,2,6};
	int iarray[]={101,203,505,10,12,54,3,5,2,1};
	int harray[]={111,21,34,6,44,76,2,5,4,1};
	int rarray[]={9,8,7,6,5,4,3,2,1,0};
	int size=10;
	printArray(array,size);
	printf("Using Selection Sort\n");
	selectionSort(array,size);
	printf("Using Insertion Sort\n");
	insertionSort(iarray,size);
	printf("Using Heap Sort\n");
	heapSort(harray,size);
	printf("Using Radix Sort\n");
	heapSort(rarray,size);
}
