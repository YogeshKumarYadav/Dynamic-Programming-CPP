#include<iostream>
#include<algorithm>
using namespace std;

int lcs(string x, string y, int m, int n){
    int t[m+1][n+1],largest=0;
    for(int i=0;i<=m;i++)
      t[i][0]=0;
    for(int j=1;j<=n;j++)
      t[0][j]=0;
    
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++){
          if(x[i-1]==y[j-1])
            t[i][j]=1+t[i-1][j-1];
          else
            t[i][j]=0;//max(t[i-1][j],t[i][j-1]); 

        largest=max(largest,t[i][j]);     
      }


    for(int i=0;i<=m;i++){
      for(int j=0;j<=n;j++)
        cout<<t[i][j]<<"  ";
      cout<<endl;
    } 

  return largest;
}
 
int lps(string x, int m){
    string s=x;
    reverse(s.begin(),s.end());
    return lcs(s,x,x.length(),s.length());
}

int main(){
    string x="uaagbcba";
    //cin>>x>>y;    
    int l=lps(x,x.length());
    cout<<l<<endl;
    return 0;
}