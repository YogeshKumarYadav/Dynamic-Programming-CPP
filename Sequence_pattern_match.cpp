#include<iostream>
using namespace std;

bool seq_match(string x, string y, int m, int n)
{   int t[m+1][n+1];
    for(int i=0;i<=m;i++)
      t[i][0]=0;
    for(int j=1;j<=n;j++)
      t[0][j]=0;
    
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      {
          if(x[i-1]==y[j-1])
           t[i][j]=1+t[i-1][j-1];
            
          else
            t[i][j]=max(t[i-1][j],t[i][j-1]); 
            
      }


    for(int i=0;i<=m;i++)
    { for(int j=0;j<=n;j++)
        cout<<t[i][j]<<"  ";
      cout<<endl;
    } 

  if(t[m][n]==m)
    return true;
  else
    return false;  
}
 
int main()
{
    string x,y;
    int m,n;
    x="AXY";
    y="ADXCPY";
    //cin>>x>>y;
    m=x.length();
    n=y.length();
    bool l=seq_match(x,y,m,n);
    cout<<l<<endl;
    return 0;
}