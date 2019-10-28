#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
vector<int> a[maxn];
int main(){
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i ++){
		int tmp, cnt = 0;
		cin>>tmp;
		while(tmp){
			a[tmp].push_back(cnt);
			tmp /= 2;
			cnt ++;
		}
	}
	int ans = INT_MAX;
	for(int i = 1; i <= 200*1000; i ++){
		if(a[i].size() >= k){
			sort(a[i].begin(), a[i].end());
			ans = min(ans, accumulate(a[i].begin(), a[i].begin()+k, 0));
		}
	}
	cout<<ans<<endl;
	return 0;
}

