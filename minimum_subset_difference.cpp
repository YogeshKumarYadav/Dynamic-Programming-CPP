#include<iostream>
using namespace std;

int subset_sum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++)
      t[i][0]=true;
    for(int j=1;j<=sum;j++)
      t[0][j]=false;

    for(int i=1;i<=n;i++)
      for(int j=1;j<=sum;j++)
      {
          if(sum>=arr[i-1])
              t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
          else
              t[i][j] = t[i-1][j];    
      }    
    int mn=INT_MAX; 
    for(int i=1;i<=sum/2;i++)
        if(t[n][i]==true) 
          mn = min(mn , sum-2*i);
          
    return mn;

}

int main()
{
    int arr[]={1,6,11,5};
    int sum=0;
    for(int i=0;i<4;i++)
      sum+=arr[i];
    int dif = subset_sum(arr,sum,4);  
    cout<<endl<<dif;
    return 0;
}