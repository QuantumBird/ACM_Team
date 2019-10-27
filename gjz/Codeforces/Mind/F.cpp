#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int main(){
	int R, C;
	cin>>R>>C;
	ll ans = 1;
	while(R --) ans = ans * 2 % mod;
	while(C --) ans = ans * 2 % mod;
	cout<<ans<<endl;
	return 0;
}


