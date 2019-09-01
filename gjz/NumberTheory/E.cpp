#include<bits/stdc++.h>
using namespace std;
#define MAXD 40000
typedef long long ll;
const ll P = 999911659;
const ll m[4] = {2,3,4679,35617};

ll i,j,n,q,cnt,ans,x;
ll a[10],factor[100010];
ll fac[MAXD+1][5];

inline void exgcd(ll a,ll b,ll &x,ll &y)
{
        if (b == 0)
        {
                x = 1;
                y = 0;    
        }    else
        {
                exgcd(b,a%b,y,x);
                y -= a / b * x;
        }
} 
inline ll CRT()
{
        int i;
        ll res = 0,M,T,x;
        for (i = 0; i < 4; i++)
        {
                M = (P - 1) / m[i];
                exgcd(M,m[i],T,x);
                T = (T % m[i] + m[i]) % m[i];
                res = (res + (a[i] * M % (P - 1) * T % (P - 1)) % (P - 1)) % (P - 1);
        }
        return res;
}
inline ll power(ll a,ll n,ll p)
{
        ll b = a,res = 1;
        while (n)
        {
                if (n & 1) res = res * b % p;
                b = b * b % p;
                n >>= 1;
        }
        return res;
}
inline void init()
{
        int i,j;
        for (i = 0; i < 4; i++) fac[0][i] = 1;
        for (i = 1; i <= MAXD; i++)
        {
                for (j = 0; j < 4; j++)
                {
                        fac[i][j] = fac[i-1][j] * i % m[j];
                }
        }
}
inline ll C(ll x,ll y,ll p)
{
        if (x < y) return 0;
        if (y == 0) return 1;
        return fac[x][p] * power(fac[y][p]*fac[x-y][p]%m[p],m[p]-2,m[p]) % m[p];    
} 
inline ll lucas(ll x,ll y,ll p)
{
        if (y == 0) return 1;
        else return lucas(x/m[p],y/m[p],p) * C(x%m[p],y%m[p],p) % m[p]; 
}
int main() 
{
    
        scanf("%lld%lld",&n,&q);
        if (q == P)
        {
                printf("0\n");
                return 0;
        }
        cnt = 0;
        for (i = 1; i <= sqrt(n); i++)
        {
                if (n % i == 0)
                {
                        factor[++cnt] = i;
                        if (i * i != n) factor[++cnt] = n / i;
                }        
        }
        init();
        for (i = 1; i <= cnt; i++)
        {
                for (j = 0; j < 4; j++)    
                {
                        a[j] = lucas(n,factor[i],j);    
                }    
                x = (x + CRT()) % (P - 1);
        }
        ans = power(q,x,P);
        printf("%lld\n",ans);
        
        return 0;
    
}

