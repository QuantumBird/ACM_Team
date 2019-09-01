#include <iostream>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0){ 
        x = 1; 
        y = 0; 
        return a; 
    }
    ll d = ex_gcd(b, a % b, x, y);
    ll t = y;
    y = x - (a / b) * y;
    x = t;
    return d;
}
ll inv(ll n, ll p) {
    ll x, y;
    ex_gcd(n, p, x, y);
    return (x % p + p) % p;                 
}
ll C(ll n, ll m, ll p) {
    ll ans = 1;
    for(ll i = 1; i <= m; ++i) 
        ans = ans * (n - i + 1) % p * inv(i, p) % p;
    return ans;
}
int main() {
    int T, kase = 0; 
    //cin >> T;
    ll n, m, p;
    while(cin>>n>>m>>p) {
        //ll n, m, p;
        //cin >> n >> m >> p;
        //cout << C(n, m, p) << endl;
        int a = (C(n + 1, m + 1, p) + m) % p;
        int b = (C(n + 1, m, p) + n - m) % p;
        cout<<"Case #"<< ++ kase<<": ";
        cout<<(n / 2 >= m? b % p: a % p)<<endl; 
    }
    return 0;
}

