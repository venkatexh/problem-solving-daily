#include <iostream>
using namespace std;

void segment(int arr[], int n)
{
    int index = 0;
    for(int i=0;i<n;i++)
    {
        while(index <n && arr[index]<0)
        {
            index++;
        }
        if(arr[i]<0)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main()
{
    cout<<"Enter n \n";
    int n;
    cin>>n;
    int *arr =  new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    segment(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}