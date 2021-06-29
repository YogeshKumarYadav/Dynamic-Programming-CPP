#include<iostream>
using namespace std;

int static t[10][10];
void initialize()
{  for(int i=0;i<10;i++)
     for(int j=0;j<10;j++)
        t[i][j]=-1;
}

int lcs(string x, string y, int m, int n)
{   
    if(m==0 || n==0 )
      return 0;
    
    if(t[m][n]!=-1)
      return t[m][n];
    
    if(x[m-1] == y[n-1])
      return t[m][n] = 1+lcs(x,y,m-1,n-1);
    
    else
      return t[m][n] = max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
}
 
int main()
{
    string x,y;
    int m,n;
    x="abcd";
    y="aced";
    //cin>>x>>y;
    m=x.length();
    n=y.length();
    initialize();
    int l=lcs(x,y,m,n);
    cout<<l<<endl;
   /* for(int i=0;i<10;i++)
    { for(int j=0;j<10;j++)
        cout<<t[i][j]<<"  ";
    cout<<endl;
    }*/
    return 0;
}