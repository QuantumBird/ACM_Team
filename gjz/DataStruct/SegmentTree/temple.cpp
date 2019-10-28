#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;

struct Node{
	int l, r, data;
	Node():l(0), r(0), data(0){};
};

Node st[maxn<<2];
int a[maxn];

void update(int idx){
	st[idx].data = st[idx << 1].data + st[idx << 1 | 1].data;
}

void build(int idx, int l, int r){
	st[idx].l = l;
	st[idx].r = r;
	if(l == r){
		st[idx].data = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(idx << 1, l, mid);
	build(idx << 1 | 1, mid + 1, r);
	update(idx);
}

void add(int idx, int pos, int dif){
	if(st[idx].l == st[idx].r){
		st[idx].data += dif;
		return ;
	}
	int mid = (st[idx].l + st[idx].r) / 2;
	if(pos <= mid) add(idx << 1, pos, dif);
	if(pos > mid) add(idx << 1 | 1, pos, dif);
	update(idx);
}

int query(int idx, int l, int r){
	if(l <= st[idx].l && st[idx].r <= r) return st[idx].data;
	int mid = (st[idx].l + st[idx].r) / 2;
	int res = 0;
	if(l <= mid) res += query(idx << 1, l, r);
	if(r > mid)  res += query(idx << 1 | 1, l, r);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int T, kase = 0;
	cin>>T;
	while(T --){
		int n;
		cin>>n;
		for(int i = 1; i <= n; i ++) cin>>a[i];
		cout<<"Case "<<++ kase<<":"<<endl;
		build(1, 1, n);
		string s;
		while(cin>>s, s != "End"){
			if(s == "Add"){
				int pos, dif;
				cin>>pos>>dif;
				add(1, pos, dif);
			}
			if(s == "Sub"){
				int pos, ndf;
				cin>>pos>>ndf;
				add(1, pos, -ndf);
			}
			if(s == "Query"){
				int l, r;
				cin>>l>>r;
				cout<<query(1, l, r)<<endl;
			}
		}
	}
	return 0;
}
