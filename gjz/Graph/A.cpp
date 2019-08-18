#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
const long long inf=9999999;
int x,y,z;;
int decibel[105][105];
void init()
{
    for(int i=1;i<=x;i++)
        for(int j=1;j<=x;j++)
          if(i==j) decibel[i][j]=0;
         else decibel[i][j]=inf;

}
int main()
{
     int flag=1;
    while(cin>>x>>y>>z)
    {
        
        if(!x&&!y&&!z) break;
        init();
       for(int i=1;i<=y;i++)
       {
           int m,n,q;
           scanf("%d%d%d",&m,&n,&q);
           if(decibel[m][n]>q)
                decibel[m][n]=decibel[n][m]=q;

       }
       if(flag>1) cout<<endl;
        for(int k=1;k<=x;k++)
            for(int i=1;i<=x;i++)
                for(int j=1;j<=x;j++)
                    if(decibel[i][k]!=inf&&decibel[k][j]!=inf)
                   decibel[i][j]=min(decibel[i][j],max(decibel[i][k],decibel[k][j]));
                   cout<<"Case #"<<flag++<<endl;
       for(int i=1;i<=z;i++)
       {
           int m,n;
           scanf("%d%d",&m,&n);
           if(decibel[m][n]!=inf)
           cout<<decibel[m][n]<<endl;
           else
            cout<<"no path"<<endl;

       }
    }
    return 0;
}