#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int s[maxn], mx[maxn << 2];

void pushup(int rt) {
    mx[rt] = max(mx[rt*2], mx[rt*2 + 1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        mx[rt] = s[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(l, mid, rt*2);
    build(mid + 1, r, rt*2 + 1);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r)
        return mx[rt];
    int mid = (l + r) / 2;
    int ret = 0;
    if(L <= mid)
        ret = max(ret, query(L, R, l, mid, rt*2));
    if(R > mid)
        ret = max(ret, query(L, R, mid + 1, r, rt*2 + 1));
    return ret;
}

void update(int L, int s, int l, int r, int rt) {
    if(l == r){
        mx[rt] = s;
        return ;
    }
    int mid = (l + r) / 2;
    if(L <= mid)
        update(L, s, l, mid, rt*2);
    else
        update(L, s, mid + 1, r, rt*2 + 1);
    pushup(rt);
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while(cin>>n>>m) {
        for(int i = 1; i <= n; i ++)
                cin>>s[i];
        build(1, n, 1);
        int a, b;
        char ch;
        while(m --){
            cin>>ch>>a>>b;
            if(ch == 'Q')
                cout<<query(a, b, 1, n, 1)<<endl;
            else
                update(a, b, 1, n, 1);
        }

    }
    return 0;
}
