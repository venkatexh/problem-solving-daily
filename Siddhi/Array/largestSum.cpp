/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
*/

#include <iostream>
using namespace std;

int maxSumCalc(int arr[], int n)
{
    int maxSum = INT_MIN;
    int tempSum = 0;

    for(int i=0;i<n;i++)
    {
        tempSum += arr[i];
        maxSum = maxSum<tempSum?tempSum:maxSum;
        tempSum = tempSum<0?0:tempSum;
    }

    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<maxSumCalc(arr,n)<<endl;
}