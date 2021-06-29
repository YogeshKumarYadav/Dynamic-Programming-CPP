#include<iostream>
using namespace std;

int a[1000];
void initialize()
{  for(int i=0;i<=1000;i++)
     a[i]=-1;
}

int fib(int f)
{  
   if(a[f]==-1)
   {  if(f<=1)
         a[f]=f;
      else
         a[f]=fib(f-1)+fib(f-2);
         
   }
   return a[f]; 
}

int main()
{ 
   int n;
   cout<<"Enter the position of fibonacci:- ";
   cin>>n;
   initialize();
   int f=fib(n);
   cout<<"\nFibonacci number is:- "<<f;

   return 0;
}