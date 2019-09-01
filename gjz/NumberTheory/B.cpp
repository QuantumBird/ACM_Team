#include <stdio.h>
typedef long long ll;
ll pow(ll n, ll k, ll p){
    ll ans = 1;
    while(k){
        if(k & 1)
            ans = (ans * n) % p;
        n = (n * n) % p;
        k >>= 1;
    }
    return ans;
}

ll C(ll n, ll m, ll p){
    if(m == 0) return 1;
    if(2*m > n) m = n - m;
    ll u, d;
    u = d = 1;
    for(int i = 1; i <= m; i ++){
        u = (u*(n - i + 1)) % p;
        d = (d * i) % p;
    }
    return u * pow(d, p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p){
    if(m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p);
}

int main(){
    int t;
    ll m, n, p;
    scanf("%d", &t);
    while(t --){
        scanf("%lld%lld%lld", &n, &m, &p);
        printf("%lld\n", lucas(n, m, p));
    }
    return 0;
}

