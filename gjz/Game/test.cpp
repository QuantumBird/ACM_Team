#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define POST
using namespace std;
int p[101][2];
int k;
int get_ans(int x, int y){
	int ans =INT_MAX;
	for(int i = 0; i < k; i ++){
		int L1 = abs(p[i][0] - x) + abs(p[i][1] - y);
		ans = min(ans, L1);
	}
	return ans;
}
int main(){
#ifdef POST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin>>n>>m;
	cin>>k;
	for(int i = 0; i < k; i ++){
		cin>>p[i][0]>>p[i][1];
	}
	int ans, ansx, ansy;
	ansx = ansy = 1;
	ans = get_ans(ansx, ansy);
	for(int x = 1; x <= n; x ++){
		for(int y = 1; y <= m; y ++){
			int t = get_ans(x, y);
			if(t > ans){
				ans = t;
				ansx = x;
				ansy = y;
			}
		}
	}
	cout<<ansx<<" "<<ansy<<endl;
	return 0;
}
