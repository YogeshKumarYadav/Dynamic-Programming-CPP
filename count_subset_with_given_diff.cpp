#include<iostream>
using namespace std;

int count_subset_diff(int arr[], int sum, int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++)
      t[i][0]=1;
    for(int j=1;j<=sum;j++)
      t[0][j]=0;

    for(int i=1;i<=n;i++)
      for(int j=1;j<=sum;j++)
      {
          if(sum>=arr[i-1])
            t[i][j] = (((j-arr[i-1])>n || (j-arr[i-1])<0)?0:t[i-1][j-arr[i-1]]) + t[i-1][j];
          else
            t[i][j] = t[i-1][j];
            
      }  

    for(int i=0;i<=n;i++)
    {  for(int j=0;j<=sum;j++)
        cout<<t[i][j]<<"  ";
     cout<<endl;
    }

    return t[n][sum];    
}

int main()
{
    int arr[]={1,1,2,3},sum=0,diff=1;
    sum=(diff+7)/2;
    int k=count_subset_diff(arr,sum,4);
    cout<<endl<<k;
    return 0;
}