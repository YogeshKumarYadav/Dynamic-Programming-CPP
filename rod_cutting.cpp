#include<iostream>
using namespace std;

int rod_cut(int length[], int price[], int len)
{
    int t[len+1][len+1];
    for(int i=0;i<=len;i++)
      for(int j=0;j<=len;j++)
         t[i][j]=0;

    for(int i=1;i<=len;i++)
      for(int j=1;j<=len;j++)
          if(j>=length[i-1])
             t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
          else
             t[i][j]=t[i-1][j];   
    
    for(int i=0;i<=len;i++)
    {  for(int j=0;j<=len;j++)
         cout<<t[i][j]<<"  ";
    cout<<endl;
    }
    return t[len][len]; 
}

int main()
{   
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int len=8;
    int profit=rod_cut(length,price,len);
    cout<<endl<<profit;
    return 0;
}