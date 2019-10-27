#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int mod=1e9+7;

ll qpow(ll x,ll n)
{
    ll re=1;
    while(n)
    {
        if(n&1) re=(re*x)%mod;
        n>>=1,x=(x*x)%mod;
    }
    return re;
}
vector<ll> v;
int main()
{
    ll n,x;    cin>>x>>n;
    for(ll i=2;i*i<=x;++i)
        if(x%i==0)
        {
            v.push_back(i);
            while(x%i==0)
                x/=i;
        }
    if(x!=1) v.push_back(x);
    ll ans=1;
    for(auto i:v)
    {
        ll cnt=0;
        ll temp=n/i;
        while(temp)
            cnt+=temp,temp/=i;
        ans=(ans*qpow(i,cnt))%mod;
    }
    cout<<ans<<endl;
}

