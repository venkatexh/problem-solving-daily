/*
Given two arrays a[] and b[] of size n and n respectively. The task is to find union between these two arrays. 
*/

#include <iostream>
using namespace std;


void getUnion(int a[],int b[], int n, int m)
{
    int res = a[n-1]>b[n-1]?a[n-1]:b[n-1];
    int *aux = new int[res+1];
    int ai=0,bi=0;
    cout<<a[0]<<" ";
    ++aux[a[0]];
    for(int i = 0;i<n;i++)
    {
        if(a[i] != a[i-1])
        {
            cout<<a[i]<<" ";
            ++aux[a[i]];
        }
    }

    for(int j=0; j<m;j++)
    {
        if(aux[b[j]] == 0)
        {
            cout<<b[j]<<" ";
            ++aux[b[j]];
        }
    }

    cout<<endl;

}

int getIntersection(int a[],int b[], int c[], int n, int m)
{
    int ai=0,bi=0;
    int count = -1;
    while(ai<n  && bi<m)
    {
        if(a[ai] == b[bi])
        {
            if(count>-1 && c[count] == a[ai])
            {
                ai++;bi++;
            }

            else{
                c[++count] = a[ai];
                ai++;
                bi++;
            }
        }

        else if(a[ai]<b[bi])
            ai++;
        else
            bi++;
    }

    return count;
}