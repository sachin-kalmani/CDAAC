//Write a program in C/C++/ Java to implement a Merge Sort algorithm to sort a given
//set of elements and determine the time required to sort the elements. Repeat the
//experiment for different values of n, the number of elements in the list to be sorted.
//The elements can be read from a file or can be generated using the random number
//generator
#include<stdio.h>
#include<stdlib.h>

//merge
void merge(int a[],int low,int mid,int high)
{
	int i,j,k,b[20];
	for(i=low,j=mid+1,k=0;i<=mid&&j<=high;)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}//for
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
		
	for(j=low,k=0;j<=high;j++,k++)
		a[j]=b[k];
}


//mergeSort
void mergeSort(int a[],int low,int high){
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergeSort(a,low,mid);
		mergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n"); 
}

void main(){
	int size=15;
	int arr[size];
	int i;
	for(i=0;i<size;i++)
	{
		arr[i]=rand()%10+1;
	}
	printf("Original Array\n");
	printArray(arr,size);
	mergeSort(arr,0,size-1);
	printf("Sorted Array\n");
	printArray(arr,size);
}
