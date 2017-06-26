// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2016/02/25 Chih-Ming Chang]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>
#include <stdlib.h>
#include <cassert>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
	for (int j=1;j<data.size();j++)
    	{
      		int flag=data[j];
      		int i=j-1;
      		while ((i>=0)&&(data[i]>flag))
        	{
          		data[i+1]=data[i];
          		i=i-1;
        	}
      		data[i+1]=flag;
   	 }
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    SortSubVector(data, 0, data.size() - 1);
}

// Sort subvector
void SortTool::SortSubVector(vector<int>& data, int low, int high) {
    // Function : Sort subvector
    // TODO : Please complete SortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
	if  (low<high)
	{
        	int mid1=(high-low)/2 + low;
		int mid2=mid1+1;
        	SortSubVector(data,low,mid1);
        	SortSubVector(data,mid2,high);
        	Merge(data,low,mid1,mid2,high);
	}

}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
	int n1= middle2-low;
    	int n2= high-middle1;
	
    	int *L = new int[n1+1];
	L[n1]=2147483647;
    	int *R = new int[n2+1];
	R[n2]=2147483647;

    	for (int i=0;i<n1;i++)
		L[i]=data[low+i];
	for (int j=0;j<n2;j++)
		R[j]=data[middle2+j];

	for(int i=0,j=0,k=low;k<(high+1);k++) 
	{
		if(L[i]<=R[j])
		{
			data[k]=L[i];
			i++;
		}
		else 
		{
			data[k]=R[j];
			j++;
		}
	}

	delete [] L;
	delete [] R;

}

// Quick sort method
void SortTool::QuickSort(vector<int>& data) {
    // Function : Quick sort
    // TODO : Please complete quick sort code here
	int high=data.size()-1;
	int low=0;
	QUICKSORT(data, low, high);
	for(int i=0; i<high; i++)
		assert(data[i] <= data[i+1]);
}

void SortTool::QUICKSORT(vector<int>& data, int low, int high) {
	if (low < high)
	{			
		int q = PARTITION( data, low, high);
		QUICKSORT(data, low, q-1);
		QUICKSORT(data, q+1, high);
	}
		
		
}

int SortTool::PARTITION(vector<int>& data, int low, int high) {
	
	int rnd = low + rand() % (high-(low-1));
	int tmp=data[high];
	data[high]=data[rnd];
	data[rnd]=tmp;

	int pivot=data[high];
	int p=low; //p=左端 r=右端 i=中隔板 j=進展
	int r=high;
	int i=p-1;
	int temp=0;
	
	for(int j=low;j<high;j++)
		if (data[j]<=pivot)
		{	
			i++;
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	data[high]=data[i+1];
	data[i+1]=pivot;
	return i+1;
	
}


