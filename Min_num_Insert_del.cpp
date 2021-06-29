#include<iostream>
using namespace std;

int lcs(string a, string b, int m, int n){
    int t[m+1][n+1];
    for(int i=0;i<=n;i++)
      t[i][0]=0;
    for(int j=0;j<=m;j++)
      t[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
              t[i][j]=1+t[i-1][j-1];
            else
              t[i][j]=max(t[i-1][j],t[i][j-1]);  
        }
    }  
    return t[m][n];
}

int ins(string a, string b, int m, int n){
    int i=n-lcs(a,b,a.length(),b.length());
    return i;
}

int del(string a, string b, int m, int n){
    int d=m-lcs(a,b,a.length(),b.length());
    return d;
}


int main(){
    string a="happy";
    string b="apple";
    int i=ins(a,b,a.length(),b.length());
    int d=del(a,b,a.length(),b.length());
    cout<<i<<"  "<<d<<endl;
    return 0;
}