#include<bits/stdc++.h>

using namespace std;

int MAX( int values[], int weight[], int m, int n ) 
{ 
    int table[m][n+1];
    for(int i=0;i<m;i++)
        table[i][0] = 0;
    for(int i=1;i<=n;i++)
    {
        if(weight[0]>i)
            table[0][i] = 0;
        else
            table[0][i] = values[0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-weight[i]<0)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                table[i][j] = max(table[i-1][j],values[i]+table[i-1][j-weight[i]]);
            }
        }
    }
    int i=m-1,j=n;
    vector<int> v;
    while(i>=0 && j>0)
    {
        if(i == 0)
        {
            v.push_back(weight[i]);
            break;
        }
        if(table[i][j] == table[i-1][j])
        {
            i--;
        }
        else
        {
            v.push_back(weight[i]);
            j = j-weight[i];
            i--;
        }
    }
    cout<<"Weights will be: "<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return table[m-1][n];
}
int main() 
{ 
    int values[] = {100,50,60,90};
    int weigth[] = {5,2,1,4}; 
    int m = sizeof(weigth)/sizeof(weigth[0]); 
    int n = 6; 
    cout << "Max value is: "<<MAX(values,weigth, m, n); 
    return 0; 
}