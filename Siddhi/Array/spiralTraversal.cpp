/*
Spiral Traversal of a matrix
*/

#include <iostream>
using namespace std;

void printSpiral(int **arr, int N, int M)
{
    int count = 0;
    int starti=0, startj=0, endj = M-1;
    int endi=N-1;
    while(count<=N*M)
    {
        for(int j = startj; j<= endj;j++)
            {
                cout<<arr[starti][j]<<" ";
                count++;
            }
        for(int i = starti+1;i<endi;i++)
            {
                cout<<arr[i][endj]<<" ";
                count++;    
            }
        for(int j = endj-1; j>=startj; j--)
            {
                cout<<arr[endi][j]<<" ";
                count++;
            }

        for(int i = endi-1; i>=starti+1;i--)
            {
                cout<<arr[i][startj];
                count++;
            }

        starti++;
        endi--;
        startj++;
        endj--;
    }
}