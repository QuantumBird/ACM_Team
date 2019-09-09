#include <iostream>
using namespace std;
const int maxn = 2e5 + 1;
int a[maxn];
int tre[maxn*2];
inline int lch(int p){return p << 1;}
inline int rch(int p){return p << 1 | 1;}
void pushup(int p){
    tre[p] = max(tre[lch(p)], tre[rch(p)]);
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
int query(int p, int x, int y, int l, int r){
    if(x <= l && r <= x)
        return tre[p];
    int mid = (l + r) / 2;
    int ans = -1;
    if(x <= mid)
        ans = max(ans, query(lch(p), x, y, l, mid));
    if(y > mid)
        ans = max(ans, query(rch(p), x, y, mid + 1, r));
    return ans;
}

void update(int p, int l, int r, int idx, int k){
    if(l == r){
        tre[p] = k;
        return ;
    }
    int mid = (l + r) / 2;
    if(idx <= mid)
        update(lch(p), l, mid, idx, k);
    else
        update(rch(p), mid + 1, r, idx, k);
    pushup(p);
}
int main(){
    int n, m;
    while(cin>>n>>m){
        for(int i = 1; i <= n; i ++)
            cin>>a[i];
        build(1, 1, n);
        while(m --){
            char cmd;
            int a, b;
            cin>>cmd>>a>>b;
            if(cmd == 'Q')
                cout<<query(1, a, b, 1, n)<<endl;
            if(cmd == 'U')
                update(1, 1, n, a, b);
        }
    }
    return 0;
}

    
