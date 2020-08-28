#include<bits/stdc++.h>

using namespace std;

int count(int n) 
{ 
    int arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++)
    {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}
int main() 
{ 
    int n;
    cin>>n;
    cout << "Number of ways to climb a staircase of length "<<n<<" with steps of size 1,2 and 3 is: " <<count(n); 
    return 0; 
}