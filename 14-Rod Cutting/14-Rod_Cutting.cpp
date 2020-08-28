#include<bits/stdc++.h>

using namespace std;

int MAX( int cuts[], int prices[], int m, int n ) 
{ 
    int table[m][n+1];
    for(int i=0;i<m;i++)
        table[i][0] = 0;
    for(int i=1;i<=n;i++)
    {
        if(i%cuts[0]!=0)
            table[0][i] = 0;
        else
            table[0][i] = (i/cuts[0])*prices[0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-cuts[i]<0)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                table[i][j] = max(table[i-1][j],prices[i]+table[i][j-cuts[i]]);
            }
        }
    }
    return table[m-1][n];
}
int main() 
{ 
    int cuts[] = {1,2,3,4,5,6,7,8};
    int prices[] = {1,5,8,9,10,17,17,20}; 
    int m = sizeof(cuts)/sizeof(cuts[0]); 
    int n = 12; 
    cout << "Max revenue is: "<<MAX(cuts,prices, m, n); 
    return 0; 
}