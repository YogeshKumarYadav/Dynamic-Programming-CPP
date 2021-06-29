#include<iostream>
using namespace std;

int boolexp(string str, int i, int j, bool istrue){
    if(i>j)
        return true;
    if(i==j)
        if(istrue == true){
            int v=str[i] == 'T';
            cout<<str[i]<<"  "<<i<<"\n";
            return v;
        }    
        else{
            int v=str[i] == 'F';
            cout<<str[i]<<"  "<<i<<"\n";
            return v;
        }      

    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt,lf,rt,rf;
        lt=boolexp(str,i,k-1,true);
        lf=boolexp(str,i,k-1,false);
        rt=boolexp(str,k+1,j,true);
        rf=boolexp(str,k+1,j,false);
        
        if(str[k] == '|'){
            if(istrue == true){
                ans = ans + lt*rt + lf*rt + lt*rf;
                //cout<<str[k]<<"  if  "<<lt<<rt<<"+"<<lf<<rt<<"+"<<lt<<rf<<"\n";
            }
            else
                ans = ans + lf*rf;
                //cout<<str[k]<<" else "<<lf<<rf<<"\n";
        }
        else if(str[k] == '&'){
            if(istrue == true){
                ans = ans + lt*rt;
                //cout<<str[k]<<"  if  "<<lt<<rt<<"\n";
            }    
            else{
                ans = ans + lf*rf + lf*rt + lt*rf;
                //cout<<str[k]<<" else "<<lf<<rf<<"+"<<lf*rt<<"+"<<lt<<rf<<"\n";
            }
        }
        else if(str[k] == '^'){
            if(istrue == true){
                ans = ans + lt*rf + lf*rt;
                //cout<<str[k]<<"  if  "<<lt<<rf<<"+"<<lf<<rt<<"\n";
            }    
            else{
                ans = ans + lt*rt + lf*rf;
                //cout<<str[k]<<" else "<<" "<<lt<<rt<<"+"<<lf<<rf<<"\n";
            }
        }
                
    }   
    return ans; 
}

int main(){
    string str="T|T&F^T";
    int count=boolexp(str,0,str.length()-1,true);
    cout<<count<<endl;

    return 0;
}