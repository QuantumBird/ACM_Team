#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
ll a[maxn];
ll add[maxn*2];
ll tre[maxn*2];

inline int lch(int p){return p << 1;}
inline int rch(int p){return p << 1 | 1;}

void pushdown(int p, int l, int r){
    if(add[p]){
        add[lch(p)] += add[p];
        add[rch(p)] += add[p];
        int mid = (l + r) / 2;
        tre[lch(p)] += add[p]*(mid - l + 1);
        tre[rch(p)] += add[p]*(r - mid);
        add[p] = 0;
    }
}

void pushup(int p){
    tre[p] = tre[lch(p)] + tre[rch(p)];
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

void update(int p, int l, int r, int x, int y, int k){
    if(x <= l && r <= y){
        add[p] += k;
        tre[p] += k*(r - l + 1);
        return ;
    }
    pushdown(p, l, r);
    int mid = (l + r) / 2;
    if(x <= mid)
        update(lch(p), l, mid, x, y, k);
    if(y > mid)
        update(rch(p), mid + 1, r, x, y, k);
    pushup(p);
}

int query(int p, int l, int r, int x, int y){
    if(x <= l && r <= y)
        return tre[p];
    pushdown(p, l, r);
    int mid = (l + r) / 2;
    int ans = 0;
    if(x <= mid)
        ans += query(lch(p), l, mid, x, y);
    if(y > mid)
        ans += query(rch(p), mid + 1, r, x, y);
    return ans;
}

int main(){
    int n, q;
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i = 1; i <= n; i ++) cin>>a[i];
    build(1, 1, n);
    while(q --){
        string s;
        int a, b, c;
        cin>>s>>a>>b;
        if(s == "Q")
            cout<<query(1, 1, n, a, b)<<endl;
        else{
            cin>>c;
            update(1, 1, n, a, b, c);
        }
    }
    return 0;
}
