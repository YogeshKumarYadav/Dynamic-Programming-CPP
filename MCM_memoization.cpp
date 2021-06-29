#include<iostream>
using namespace std;

int static t[10][10];
void initialize(){
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
       t[i][j]=-1;
}

int mcm(int arr[], int i, int j){
    if(i==j)
      return 0;

    if(t[i][j] != -1)
       return t[i][j];
    int cst=INT_MAX,temp;  
    for(int k=i;k<j;k++){
        temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
       // cout<<temp<<"  ";
        cst=min(cst,temp);
    } 
    return t[i][j]=cst;
}

int main(){
    int arr[]={4,2,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    initialize();
    int cost=mcm(arr,1,n-1);
    for(int i=0;i<10;i++){
     for(int j=0;j<10;j++)
       cout<<t[i][j]<<"  ";
     cout<<endl;
    }
    cout<<cost<<endl;

    return 0;
}