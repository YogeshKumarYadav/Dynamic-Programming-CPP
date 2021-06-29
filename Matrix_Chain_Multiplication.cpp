#include<iostream>
using namespace std;

int mcm(int arr[], int i, int j){
    if(i==j)
      return 0;
    int cst=INT_MAX,temp;  
    for(int k=i;k<j;k++){
        temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
       // cout<<temp<<"  ";
        cst=min(cst,temp);
    }  
    return cst;
}

int main(){
    int arr[]={10,100,20,5,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    int cost=mcm(arr,1,n-1);
    cout<<cost<<endl;

    return 0;
}