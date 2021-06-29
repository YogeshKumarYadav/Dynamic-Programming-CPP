#include<iostream>
using namespace std;

int static t[500][500];
void initialize(){
    for(int i=0;i<500;i++)
    for(int j=0;j<500;j++)
       t[i][j]=-1;
}

bool palindrome(string str, int i, int j){
    while(i<=j){
        if(str[i]==str[j]){
          i++;
          j--;
        }  
        else
          break;
    }
    if(i>j)
       return true;
    else
       return false;
}

int palin_part(string str, int i, int j){
    if(i>=j)
      return 0;

    if(palindrome(str,i,j)==true)
       return 0;

    if(t[i][j] != -1)
       return t[i][j];

    int cst=INT_MAX,temp,left,right;  
    for(int k=i;k<j;k++){
      
        temp = 1 + palin_part(str,i,k) + palin_part(str,k+1,j);
       /*
     //optimized
        if(t[i][k]!=-1)
           left=t[i][k];
        else{
            left=palin_part(str,i,k);
            t[i][k]=left;
        }
        if(t[k+1][j]!=-1)
          right=t[k+1][j];
        else{
            right=palin_part(str,k+1,j);
            t[k+1][j]=right;
        }  
        temp=1+left+right;      
         */

        cst=min(cst,temp);
    } 
    return t[i][j]=cst;
}

int main(){
    string str="aaabba";
    int n=str.length();
    initialize();
    int cost=palin_part(str,0,n-1);
    for(int i=0;i<10;i++){
     for(int j=0;j<10;j++)
       cout<<t[i][j]<<"  ";
     cout<<endl;
    }
    cout<<cost<<endl;

    return 0;
}