#include<iostream>
#include<string>
using namespace std;

bool scramble_str(string s1, string s2){
    if(s1.compare(s2)==0)
      return true;
    if(s1.length()<=1)
      return false;
    
    int n=s1.length();
    bool f=false;
    for(int k=1;k<n;k++){
        if( (scramble_str(s1.substr(0,k),s2.substr(n-k,k))==true && scramble_str(s1.substr(k,n-k),s2.substr(0,n-k))==true)
                                                                  ||
            (scramble_str(s1.substr(0,k),s2.substr(n-k,k))==true && scramble_str(s1.substr(k,n-k),s2.substr(0,n-k))==true) )
        {
            f=true;
            break;
        }      
           
    }
    return f;
}

int main(){
    string s1="GOOD",s2="DOGO";
    if(s1.length() != s2.length())
        cout<<false<<endl;
    else if(s1.length()==0 && s2.length()==0)
        cout<<false<<endl;
    else{
        bool res=scramble_str(s1,s2);
        cout<<res<<endl;
    }
       
    return 0;
}