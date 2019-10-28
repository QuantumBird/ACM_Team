#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int w[maxn], c[maxn];
typedef long long ll;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	int n, k, a;
	cin>>n>>k;
	for(int i = 1; i <= n; i ++) cin>>w[i];
	cin>>a;
	for(int i = 1; i <= n; i ++) cin>>c[i];
	ll ans = 0;
	for(int i = 1; i <= n; i ++){
		pq.push(c[i]);
		while(k < w[i]){
			if(pq.empty()){
				cout<<-1<<endl;
				return 0;
			}
			ans += pq.top();
			pq.pop();
			k += a;
		}
	}	
	cout<<ans<<endl;
	return 0;
}
