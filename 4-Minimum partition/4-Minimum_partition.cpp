#include<bits/stdc++.h>

using namespace std;

int mabs(int arr[],int n) 
{ 
    int sum=0,sum_half;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    sum_half = sum/2;
    bool table[n+1][sum_half+1];
    for(int i=0;i<=n;i++)
        table[i][0]= true;
    for(int i=1;i<=sum_half;i++)
        table[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum_half;j++)
        {
            if(j-arr[i-1]<0)
            {
                table[i][j] = table[i-1][j];
            }
            else
                table[i][j] = table[i-1][j] or table [i-1][j-arr[i-1]];
        }
    }
    int one_sum,second_sum;
    for(int i=sum_half;i>=0;i--)
    {
        if(table[n][i] == true){
            one_sum = i;
            break;
        }
    }
    second_sum = sum - one_sum;
    return abs(one_sum-second_sum);
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout << "Minimum absolute difference is: "<<mabs(arr,n); 
    return 0; 
}