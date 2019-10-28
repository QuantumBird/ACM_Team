#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll qpow(ll a, ll n){
	ll ans = 1;
	while(n){
		if(n & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	return ans;
}

int main(){
	ll n, x, ans = 0;
	cin>>n>>x;
	for(ll i = 2; i * i <= x; i ++){
		if(x % i == 0){
			ll cnt = 0;
			ll tmp = n / i;
			while(tmp){
				cnt += tmp;
				tmp /= i;
			}
			ans = (ans * qpow(i, cnt)) % mod;
			while(x % i == 0) x /= i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

