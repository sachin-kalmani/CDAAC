//Write a program in C/C++/ Java to sort a given set of elements using the Quick sort
//method and determine the time required to sort the elements. Repeat the experiment
//SPPU M.Sc. Computer Science Syllabus 2023-24 52
//for different values of n, the number of elements in the list to be sorted. The elements
//can be read from a file or can be generated using the random number generator.
#include<stdio.h>
#include<stdlib.h>


int partition(int a[],int lb,int ub)
{
	int up,down,temp,pivot;
	pivot = a[lb];
	down = lb+1;
	up = ub;
	
	do{
		while((a[down]<pivot)&&(down<=ub))
			down++;
		while((a[up]>pivot) && (up>lb))
			up--;
		if(down<up)
		{
			temp=a[up];
			a[up]=a[down];
			a[down]=temp;
		}
	}while(down<up);
	temp=a[lb];
	a[lb]=a[up];
	a[up]=temp;
	return up;
}


//quickSort
void quickSort(int arr[],int lb,int ub)
{
	int j;
	if(lb<ub)
	{
		j=partition(arr,lb,ub);
		quickSort(arr,lb,j-1);
		quickSort(arr,j+1,ub);
	}
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


void main(){
	int size=10;
	int arr[size];
	int i;
	for(i=0;i<size;i++)
	{
		arr[i]=rand()%100+1;
	}
	printf("Original Array\n");
	printArray(arr,size);
	quickSort(arr,0,size-1);
	printf("Sorted Array\n");
	printArray(arr,size);
}
