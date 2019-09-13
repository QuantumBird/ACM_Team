#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn];
int add[maxn];
int tre[maxn];
inline int lch(int p){return p << 1;}
inline int rch(int p){return p << 1 | 1;}
void pushup(int p){
    tre[p] = tre[lch(p)] + tre[rch(p)];
}
void pushdown(int p, int l, int r){
    if(add[p]){
        add[lch(p)] += add[p];
        add[rch(p)] += add[p];
        int mid = (l + r) / 2;
        tre[lch(p)] += add[p]*(m - l + 1);
        tre[rch(p)] += add[p]*(r - m);
        add[p] = 0;
    }
}
void update(int p, int x, int y, int l, int r, int k){
    if(x <= l && r <= y){
        add[p] += k;
        tre[p] += k*(r - l + 1);
        return ;
    }
    pushdown(p, l, r);
    int mid = (l + r) / 2;
    if(x <= m)
        update(lch(p), x, y, l, mid, k);
    if(y > m)
        update(rch(p), x, y, mid + 1, r, k);
    pushup(p);
}
int query(int p, int x, int y, int l, int r){
    if(x <= l && r <= y)
        return tre[p];
    pushdown(p, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if(x <= m)
        ans += query(lch(p), x, y, l, mid);
    if(y > m)
        ans += query(rch(p), x, y, mid + 1, r);
    return ans;
}
void build(int p, int l, int r){
    if(l == r){
        tre[p] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(lch(p), l, mid);
    build(rch(p), mid + 1, r);
    pushup(p);
}
int main(){



