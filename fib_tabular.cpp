#include<iostream>
using namespace std;

int fib(int f)
{  int a[f+1];
   a[0]=0;
   a[1]=1;
   for(int i=2;i<=f;i++)
     a[i]=a[i-1]+a[i-2];
   
   return a[f];  
}

int main()
{   
    int n;
    cout<<"Enter position of fibonacci number:- ";
    cin>>n;
    int f=fib(n);
    cout<<"\nFibonacci number is:- "<<f;
    
    return 0;
}