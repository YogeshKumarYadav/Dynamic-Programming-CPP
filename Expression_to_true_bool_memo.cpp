#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string , int> mp;

int boolexp(string str, int i, int j, bool istrue){
    if(i>j)
        return false;
    if(i==j)
        if(istrue == true)
            return str[i] == 'T';
        else
            return str[i] == 'F';  
    
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));

    if(mp.find(temp)!=mp.end())
       return mp[temp];

    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt,lf,rt,rf;
        lt=boolexp(str,i,k-1,true);
        lf=boolexp(str,i,k-1,false);
        rt=boolexp(str,k+1,j,true);
        rf=boolexp(str,k+1,j,false);
        
        if(str[k] == '|')
            if(istrue == true)
                ans = ans + lt*rt + lf*rt + lt*rf;
            else
                ans = ans + lf*rf;

        else if(str[k] == '&')
            if(istrue == true)
                ans = ans + lt*rt;
            else
                ans = ans + lf*rf + lf*rt + lt*rf;

        else if(str[k] == '^')
            if(istrue == true)
                ans = ans + lt*rf + lf*rt;
            else
                ans = ans + lt*rt + lf*rf;
    }    
    mp[temp]=ans;
    return ans; 
}

int main(){
    string str="T|T&F^T";
    mp.clear();
    int count=boolexp(str,0,str.length()-1,true);
    for(map<string,int>::iterator i=mp.begin() ; i!=mp.end() ; i++)
       cout<<i->first<<" = "<<i->second<<endl;
    cout<<endl<<count<<endl;

    return 0;
}