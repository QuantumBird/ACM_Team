#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int a[maxn];
struct Node{
	int data, l, r;
	Node():data(0), l(0), r(0){}
};
Node st[maxn<<2];

void update(int idx){
	st[idx].data = max(st[idx << 1].data, st[idx << 1 | 1].data);
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

void change(int idx, int pos, int val){
	if(st[idx].l == st[idx].r){
		st[idx].data = val;
		return ;
	}
	int mid = (st[idx].l + st[idx].r) / 2;
	if(pos <= mid) change(idx << 1, pos, val);
	if(pos >  mid) change(idx << 1 | 1, pos, val);
	update(idx);
}

int query(int idx, int l, int r){
	if(l <= st[idx].l && st[idx].r <= r) return st[idx].data;
	int mid = (st[idx].l + st[idx].r) / 2;
	int res = 0;
	if(l <= mid) res = max(res, query(idx << 1, l, r));
	if(r >  mid) res = max(res, query(idx << 1 | 1, l, r));
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int m, n;
	while(cin>>m>>n){
		for(int i = 1; i <= m; i ++) cin>>a[i];
		build(1, 1, m);
		int a, b;
		while(n --){
			char opt;
			cin>>opt>>a>>b;
			switch(opt){
				case 'Q': cout<<query(1, a, b)<<endl;
					  break;
				case 'U': change(1, a, b);
					  break;
			}
		}
	}
	return 0;
}


