#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
struct Node{
	int l, r, sum, lazy;
	Node(): l(0), r(0), sum(0), lazy(0){}
};
int a[maxn];
Node st[maxn << 2];

inline void update(int idx){
	st[idx].sum = st[idx << 1].sum + st[idx << 1 | 1].sum;
}

void build(int idx, int l, int r){
	st[idx].l = l;
	st[idx].r = r;
	if(l == r){
		st[idx].sum = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(idx << 1, l, mid);
	build(idx << 1 | 1, mid + 1, r);
	update(idx);
}

void changeSegment(int idx, int l, int r, int dif){
	if(st[idx].l == l && st[idx].r == r){
		st[idx].sum += (r - l + 1) * dif;
		st[idx].lazy += dif;
		return ;
	}
	int mid = (st[idx].l + st[idx].r) / 2;
	if(r <= mid) changeSegment(idx << 1, l, r, dif);
	else if(l > mid) changeSegment(idx << 1 | 1, l, r, dif);
	else{
		changeSegment(idx << 1, l, mid, dif);
		changeSegment(idx << 1 | 1, mid + 1, r, dif);
	}
	update(idx);
}

void pushdown(int idx){
	if(st[idx].l == st[idx].r){
		st[idx].lazy = 0;
		return ;
	}
	st[idx << 1].sum =\
		(st[idx << 1].r - st[idx << 1].l + 1)*st[idx].lazy;
	st[idx << 1 | 1].sum =\
		(st[idx << 1 | 1].r - st[idx << 1 | 1].l + 1)*st[idx].lazy;
	st[idx << 1].lazy += st[idx].lazy;
	st[idx << 1 | 1].lazy += st[idx].lazy;
	st[idx].lazy = 0;
}

int query(int idx, int l, int r){
	if(st[idx].lazy) pushdown(idx);
	if(st[idx].l == l && st[idx].r == r) return st[idx].sum;
	int mid = (st[idx].l + st[idx].r) / 2;
	if(r <= mid) return query(idx << 1, l, r);
	if(l > mid) return query(idx << 1 | 1, l, r);
	return query(idx << 1, l, mid) + query(idx << 1 | 1, mid + 1, r);
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i ++) cin>>a[i];
	build(1, 1, n);
	while(m --){
		char opt;
		int a, b, c;
		cin>>opt;
		switch(opt){
			case 'Q':{
				cin>>a>>b;
				cout<<query(1, a, b)<<endl;
			}; break;
			case 'C':{
				cin>>a>>b>>c;
				changeSegment(1, a, b, c);
			}; break;
		}
	}
	return 0;
}


