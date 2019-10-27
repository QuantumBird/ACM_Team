#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 1;
typedef long long ll;
ll phi(ll n){  
    int ans=n,temp=n;  
    for(int i=2;i*i<=temp;i++){  
        if(temp%i==0){  
            ans-=ans/i;  
            while(temp%i== 0) 
                temp/=i;  
        }  
    }  
    if(temp>1) 
        ans -= ans / temp;  
    return ans;  
}  
ll qpow(ll a, ll p, ll m){
    ll ans = 1;
    while(p){
        if(p & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        p /= 2;
    }
    return ans % m;
}
ll get_ans(ll a, ll b, ll m){
    if(b == 0) return 1;
    ll tmp = __gcd(a, m);
    ll ph = phi(m);
    if(tmp == 1)
        return qpow(a, get_ans(a, b - 1, m) % ph, m);
    else if(b < ph)
        return qpow(a, get_ans(a, b - 1, m), m);
    return qpow(a, get_ans(a, b - 1, m) % ph + ph, m);
}
int main(){
    ll a, b, m, t;
    cin>>t;
    while(t --){
        cin>>a>>b>>m;
        cout<<get_ans(a, b, m)<<endl;
    }
    return 0;
}
