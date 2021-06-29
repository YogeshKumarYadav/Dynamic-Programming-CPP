#include<iostream>
using namespace std;

int static t[100][1000];
void initialize()
{
    for(int i=0;i<100;i++)
      for(int j=0;j<1000;j++)
        t[i][j]=-1;
}

int knapsack(int wt[], int val[], int w, int n)
{   if(n<0)
     return 0;
    if(t[n][w]!=-1)
      return t[n][w];
    if(wt[n-1]<=w)
        return t[n][w]=max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    else
       return t[n][w]=knapsack(wt,val,w,n-1);
}

int main()
{ 
    int wt[4]={1,3,4,5};
    int val[4]={1,4,5,7};
    int w=7;
    initialize();
    int k=knapsack(wt,val,w,4);
    for(int i=1;i<=4;i++)
    {  for(int j=0;j<=7;j++)
         cout<<t[i][j]<<"  ";
      cout<<endl;   
    }
    cout<<endl<<k;

    return 0;
}