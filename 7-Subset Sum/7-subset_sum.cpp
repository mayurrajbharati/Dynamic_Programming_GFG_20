#include<bits/stdc++.h>

using namespace std;

bool subset(int arr[],int n,int val) 
{ 
    bool table[n+1][val+1];
    for(int i=0;i<=n;i++)
        table[i][0]= true;
    for(int i=1;i<=val;i++)
        table[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=val;j++)
        {
            if(j-arr[i-1]<0)
            {
                table[i][j] = table[i-1][j];
            }
            else
                table[i][j] = table[i-1][j] or table [i-1][j-arr[i-1]];
        }
    }
    return table[n][val];
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n],val;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter sum:"<<endl;
    cin>>val;
    if(subset(arr,n,val))
        cout<<"Yes! It is possible to have subsets!"<<endl;
    else
        cout<<"Alas! Not possible to have subsets!"<<endl;
     
    return 0; 
}