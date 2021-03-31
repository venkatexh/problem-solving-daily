#include <iostream>
#include <algorithm>
using namespace std;

int countTriplet(int arr[], int n, int sum)
{
    sort(arr,arr+n);
    int count = 0;
    for(int i=0;i<n-1;i++)
    {
        int l = n-1;
        int s = i+1;
        while(s<l)
        {
            if(arr[i]+arr[l]+arr[s]==sum)
                {
                    count++;
                    cout<<"%d %d %d \n",arr[i],arr[l],arr[s];
                }
            else if (arr[i] + arr[l] + arr[s] < sum)
                s++;
            else 
                l--;

        }
    }
}