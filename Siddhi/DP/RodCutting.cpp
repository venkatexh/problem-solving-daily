/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces
*/

#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a>b?a:b;
}
int getMax(int price[], int n)
{
    int *dp = new int[n+1];
    dp[0] = 0;

    for(int i=1;i<n;i++)
    {
        int max_val = INT64_MAX;
        for(int j=0;j<n;j++)
            max_val=max(max_val, price[j]+dp[i-j-1]);
        dp[i] = max_val;
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int *price = new int[n];
    for(int i=0;i<n;i++)
        cin>>price[i];
    
    cout<<"Maximum obtainable value is "<< getMax(price, n);
}