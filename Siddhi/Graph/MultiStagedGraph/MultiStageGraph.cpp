#include <iostream>
using namespace std;

int min(int a, int b)
{
    return a<b?a:b;
}
int getDistance(int graph[8][8], int N)
{
    int dp[8];
    dp[N-1] = 0 ;// Distance from destination to destination is 0

    for(int i=N-2;i>=0;i--)
    {
        dp[i] = INT_MAX;

        for(int j=i;i<N;j++)
        {
            if(graph[i][j] == INT_MAX)
                continue;
            dp[i] = min(dp[i], graph[i][j]+dp[j]);
        }
    }

    return dp[0];
}

int main()
{
    /*
    int N;
    cin>>N;
    int **graph = new int*[N];
    for(int i=0;i<N;i++)
        graph[i] = new int[N];

    cout<<"\t";
    for(int i =0;i<N;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(int i =0;i<N;i++)
    {   cout<<i<<"\t";
        for(int j = 0; j<N; j++)
        {
            int temp;
            cin>>temp;
            if(temp == -1)
                temp = INT_MAX;
            graph[i][j] = temp;
        }
        cout<<endl;
    }
    */
    int graph[8][8] =
      {{INT_MAX, 1, 2, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 4, 11, INT_MAX, INT_MAX},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9, 5, 16, INT_MAX},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 18},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 13},
       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2}};
    cout<<getDistance(graph,8);

}