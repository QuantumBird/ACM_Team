#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL t,n,l,r,cur,k,a[N],ans[N];
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);
	while(cin >> t){
		while(t--){
			cin >> n;
			a[1] = 0;
			for(int i = 2;i <= n;i++){
				cin >> a[i];
				a[i] += a[i - 1];
			}
			l = 2,r = n - 1,k = 3,ans[1] = 0,ans[2] = cur = a[n];
			for(int i = 3;i <= n;i++){
				if(i & 1){
					ans[k] = ans[k - 1] + cur;
					k++;
				}
				else{
					cur += a[r] - a[l];
					ans[k] = ans[k - 1] + cur;
					l++,r--,k++;
				}
			}
			for(int i = 1;i < k;i++){
                if(i == 1) 
					cout << ans[i];
                else 
					cout << " " << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}

