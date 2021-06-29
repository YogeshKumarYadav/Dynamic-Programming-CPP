#include <bits/stdc++.h>
using namespace std;

int palindromicPartition(string str)
{
        bool t[str.length()][str.length()];
        for(int k=0;k<str.length();k++){
            for(int i=0,j=k;i<str.length();i++,j++){
                if(k==0)
                  t[i][j]=true;
                else if(k==1)
                  t[i][j]=str[i]==str[j];
                else{
                    if(str[i]==str[j] && t[i+1][j-1]==true)
                       t[i][j]=true;
                    else
                       t[i][j]=false;   
                }  
            }
        }

        int ans[str.length()];
        ans[0]=0;
        for(int j=1;j<str.length();j++){
            if(t[0][j])
              ans[j]=0;
            else{
                int mans=INT_MAX;
                for(int i=j;i>=1;i--){
                    if(t[i][j])
                        mans=min(ans[i-1],mans);        
                }
                ans[j]=mans+1;
            }  
        }

        for(int l=0;l<str.length();l++)
        {   for(int p=0;p<str.length();p++)
                cout<<t[l][p]<<"  ";
            cout<<endl;  
        }
        cout<<endl<<endl; 
        for(int e=0;e<str.length();e++)
             cout<<ans[e]<<"  ";
        cout<<endl<<endl;

        return ans[str.length()-1];
}

int main(){
    string str="aaabbacc";
    cout<<palindromicPartition(str)<<"\n";
    
    return 0;
} 