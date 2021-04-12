/*
This is an optimization over method 1 if QuickSort is used as a sorting algorithm in first step.
In QuickSort, we pick a pivot element, then move the pivot element to its correct position and partition the array around it.
The idea is, not to do complete quicksort, but stop at the point where pivot itself is k’th smallest element.
Also, not to recur for both left and right sides of pivot, but recur for one of them according to the position of pivot. 
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(&arr[i++],&arr[j]);
        }
    }

    swap(&arr[i],&arr[high]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if(k>0 && k<r-l+1)
    {
        int pos = partition(arr,l,r);
        if(pos-l == k-1)
            return arr[pos];
        if(pos-l > k-1)
            return kthSmallest(arr,l,pos-1,k);
        
        return kthSmallest(arr,pos+1,r,k-pos+l-1);
    }
    return INT_MAX;
}


int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    cout<<kthSmallest(arr,0,6,3);
}