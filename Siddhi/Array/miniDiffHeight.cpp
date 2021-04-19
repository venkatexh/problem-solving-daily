/*
Given heights of n towers and a value k.
We need to either increase or decrease height of every tower by k (only once) where k > 0.
The task is to minimize the difference between the heights of the longest and the shortest tower after modifications, and output this difference.
*/


#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int k, int n)
{
    sort(arr, arr+n);
    int ans = arr[n-1] - arr[0];

    int small = arr[0]+k;
    int big = arr[n-1]-k;

    if(small > big)
    {
        swap(small,big);
    }
}