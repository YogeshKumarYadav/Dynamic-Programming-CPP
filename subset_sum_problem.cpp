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
    for(int i=0;i<n+1;i++)
    {  for(int j=0;j<sum+1;j++)
        cout<<t[i][j]<<"  ";
     cout<<endl;
    }
    return t[n][sum];    
}

int main()
{
    int arr[5]={2,3,7,8,10};
    int sum =11;
    bool res = subset_sum(arr,sum,5);
    cout<<endl<<res;
   
    return 0;
}