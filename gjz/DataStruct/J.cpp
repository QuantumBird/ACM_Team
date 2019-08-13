#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn << 2];
int col[maxn << 2];

void pushup(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m) {
    if(col[rt]) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        sum[rt << 1] = col[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] = col[rt] * (m >> 1);
        col[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 1;
    if(l == r)
        return ;
    int mid = (l + r) / 2;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return ;
    }
    pushdown(rt, r - l + 1);
    int mid = (r + l) / 2;
    if(L <= mid)
        update(L, R, c, l, mid, rt << 1);
    if(R > mid) 
        update(L, R, c, mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    pushdown(rt, r - l + 1);
    int ret = 0;
    int mid = (l + r) / 2;
    if(L <= mid)
        ret += query(L, R, l, mid, rt << 1);
    if(R > mid) 
        ret += query(L, R, mid + 1, r, rt << 1 | 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int T, n, q, a, b, c, kase;
    while(cin>>T) {
        //cin>>n>>q;
        kase = 0;
        while(T --) {
            cin>>n>>q;
            build(1, n, 1);
            for(int i = 0; i < q; i ++) {
                cin>>a>>b>>c;
                update(a, b, c, 1, n, 1);
            }
//            for(int i = 1; i <= 20; i ++)
//                cout<<sum[i]<<endl;
            printf("Case %d: The total value of the hook is %d.\n", ++ kase, sum[1]);
        }
    }
    return 0;
}

