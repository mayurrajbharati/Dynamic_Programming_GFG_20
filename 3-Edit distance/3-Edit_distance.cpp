#include<bits/stdc++.h>

using namespace std;

int EDDIST( string s1, string s2 ) 
{ 
    int n = s1.length();
    int m = s2.length();
    int table[m+1][n+1];
    for(int i=0;i<=m;i++)
        table[i][0] = i;
    for(int i=1;i<=n;i++)
        table[0][i] = i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[j-1] == s2[i-1])
            {
                table[i][j] = table[i-1][j-1];
            }
            else
                table[i][j] = 1 + min(min(table[i-1][j-1],table[i-1][j]),table[i][j-1]);
        }
    }
    return table[m][n];
}
int main() 
{ 
    string s1,s2;
    cin>>s1>>s2;
    cout << "Minimum operations required are: "<<EDDIST(s1,s2); 
    return 0; 
}