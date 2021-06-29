#include<iostream>
using namespace std;

int static t[10][50];
void initialize(){
  for(int i=0;i<10;i++)
     for(int j=0;j<50;j++)
        t[i][j]=-1;
}

int egg_drop(int e, int f){
    if(f<=0)
      return 0;
    if(e==1)
      return f;
    if(f==0 || f==1)
      return f;
    
    if(t[e][f]!=-1)
      return t[e][f];

    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
       int temp=1 + max( egg_drop(e-1,k-1) , egg_drop(e,f-k) );
       mn=min(mn,temp);
    }    
    return t[e][f]=mn;
}

int main(){
    int e=2,f=7;
    initialize();
    int m=egg_drop(e,f);
    cout<<m<<endl;
    return 0;
}