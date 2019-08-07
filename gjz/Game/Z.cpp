/*
#include<stdio.h>
#include<math.h>
int  main ()
{
   int n,m,k,t;
   while(~scanf("%d%d",&n,&m))
   {  
       if(n<m)
       {
              t=m;
              m=n;
              n=t;
       }
       k=n-m;
       if(int(k*(1+sqrt(5.0))/2)==m) 
       printf("0\n");
       else
       printf("1\n");
    }
    return 0;
}
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int a, b;
    while(cin>>a>>b){
        int n = max(a, b);
        int m = min(a, b);
        int k = n - m;
        if(int(k*(1 + sqrt(5.0))/2) == m)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}