#include<bits/stdc++.h>

using namespace std;

int LCS( string s1, string s2 ) 
{ 
    int n = s1.length();
    int m = s2.length();
    int table[m+1][n+1];
    for(int i=0;i<=m;i++)
        table[i][0] = 0;
    for(int i=1;i<=n;i++)
        table[0][i] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                table[i][j] = 1 + table[i-1][j-1];
            }
            else
            {
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[m][n];
}
int main() 
{ 
    string s1,s2;
    cin>>s1>>s2;
    cout << "Longest Common Subsequence length is: "<<LCS(s1,s2); 
    return 0; 
}