#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int dp[maxn];
int a[maxn];
int main(){
	int n, k, l;
	cin>>n>>k>>l;
	for(int i = 0; i < n*k; i ++) cin>>a[i];
	sort(a, a + n*k);

