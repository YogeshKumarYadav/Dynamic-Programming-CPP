#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string lcs(string x, string y, int m, int n)
{   int t[m+1][n+1];
    for(int i=0;i<=m;i++)
      t[i][0]=0;
    for(int j=1;j<=n;j++)
      t[0][j]=0;

    string str1="";
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
    int i=m;
    int j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str1.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1])
              i--;
            else
              j--;  
        }
    }
  reverse(str1.begin(), str1.end());
  return str1;
}
 
int main()
{
    string x,y;
    int m,n;
    x="acbdfgk";
    y="abcdaf";
    //cin>>x>>y;
    m=x.length();
    n=y.length();
    string l=lcs(x,y,m,n);
    cout<<l<<endl;
    return 0;
}