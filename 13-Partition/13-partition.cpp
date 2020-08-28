#include<bits/stdc++.h>

using namespace std;

bool partition(int arr[],int n) 
{ 
    int sum =0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(sum%2!=0)
        return false;
    int half_sum = sum/2;
    bool table[n+1][half_sum+1];
    for(int i=0;i<=n;i++)
        table[i][0]= true;
    for(int i=1;i<=half_sum;i++)
        table[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=half_sum;j++)
        {
            if(j-arr[i-1]<0)
            {
                table[i][j] = table[i-1][j];
            }
            else
                table[i][j] = table[i-1][j] or table [i-1][j-arr[i-1]];
        }
    }
    if(table[n][half_sum]==true)
        return true;
    else
        return false;
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(partition(arr,n))
        cout<<"Yes! It is possible to have subsets!"<<endl;
    else
        cout<<"Alas! Not possible to have subsets!"<<endl;
     
    return 0; 
}