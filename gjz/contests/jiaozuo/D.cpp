    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cmath>
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int maxn=100005;
     
    int main()
    {
        int t;  scanf("%d",&t);
        while(t--)
        {
           double a,b,r,d;
           cin>>a>>b>>r>>d;
           double k=3.14159265358979323846;
           d= (k*d)/180.0;
     
           double w;
           if( d >= atan(b/(a+r))){
            w=sqrt((b*b+(a+r)*(a+r)))-r;
           }
           else{
            w=(a+r)/cos(d)-r+sin(d)*(b-(a+r)*tan(d));
           }
     
           printf("%.12lf\n",w);
        }
     
        return 0;
    }
