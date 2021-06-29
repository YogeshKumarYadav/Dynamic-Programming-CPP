#include<iostream>
using namespace std;

bool subset_sum(int arr[],int sum, int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++)
      t[i][0]=true;
    for(int j=1;j<=sum;j++)
      t[0][j]=false;

    for(int i=1;i<=n;i++)
      for(int j=1;j<=sum;j++)
      {
          if(arr[i-1]<=sum)
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
          else
            t[i][j] = t[i-1][j];  
      }

    return t[n][sum];    
}

bool equal_subset(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
      sum+=arr[i];
    if(sum%2!=0)
      return false;
    else  
      return subset_sum(arr,sum/2,n);  
}

int main()
{
    int arr[]={1,7,11,5};
    bool k=equal_subset(arr,4);
    cout<<k<<endl;
    return 0;
}