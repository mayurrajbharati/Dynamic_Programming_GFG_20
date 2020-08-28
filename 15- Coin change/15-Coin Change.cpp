#include<bits/stdc++.h>

using namespace std;

int count( int S[], int m, int n ) 
{ 
    int table[m+1][n+1];
    for(int i=0;i<=m;i++)
    	table[i][0]=1;
    for(int i=1;i<=n;i++)
    	table[0][i]=0;
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(j-S[i-1]<0){
    			table[i][j] = table[i-1][j];	
    		}
    		else
    			table[i][j] = table[i][j-S[i-1]]+table[i-1][j];
    	}
    }
    return table[m][n];
}
int main() 
{ 
    int arr[] = {2,4,5}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 6; 
    cout << count(arr, m, n); 
    return 0; 
} 