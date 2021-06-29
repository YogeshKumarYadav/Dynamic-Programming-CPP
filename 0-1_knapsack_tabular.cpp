#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int w, int n)
{
    int t[n+1][w+1];
    for(int i=0;i<=n;i++)
      for(int j=0;j<=w;j++)
         t[i][j]=0;

    for(int i=1;i<=n;i++)
       for(int j=1;j<=w;j++)
       {
           if(wt[i-1]<=j)
             t[i][j]=max(t[i-1][j],t[i-1][j-wt[i-1]]+val[i-1]);
           else
             t[i][j]=t[i-1][j];
             
       }    

    for(int i=1;i<=n;i++)
    {  for(int j=0;j<=w;j++)
         cout<<t[i][j]<<"  ";
      cout<<endl;   
    }
    return t[n][w];     
}

int main()
{
    int wt[4]={1,3,4,5};
    int val[4]={1,4,5,7};
    int w=7;
    int k=knapsack(wt,val,w,4);
    cout<<endl<<k;

    return 0;
}