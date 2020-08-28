#include<bits/stdc++.h>

using namespace std;

int lis(int arr[],int n) 
{ 
    int LIS[n];
    for(int i=0;i<n;i++)
        LIS[i]=1;
    int i=0;
    for(int j=1;j<n;j++)
    {
        i =0;
        while(i<j)
        {
            if(arr[i]<=arr[j])
            {
                LIS[j] = max(LIS[j], 1+LIS[i]);
                i++;
            }
            else
                i++;
        }
    }
    int MAX = LIS[0],index;
    for(int i=1;i<n;i++)
        MAX = max(MAX,LIS[i]);
    return MAX;
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout << "Longest Increasing Subsequence length is: "<<lis(arr,n); 
    return 0; 
}