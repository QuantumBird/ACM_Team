#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e5 + 1;
typedef struct node{
    int sum;
    int l, r;
} node;
node tre[maxn*2];
int a[maxn];
inline int lch(int p){return p << 1;}
inline int rch(int p){return p << 1 | 1;}
void update(int p){
    tre[p].sum = tre[lch(p)].sum + tre[rch(p)].sum;
}
void build(int p, int l, int r){
    tre[p].l = l;
    tre[p].r = r;
    if(l == r){
        tre[p].sum = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(lch(p), l, mid);
    build(rch(p), mid + 1, r);
    update(p);
}
int query(int p, int l, int r){
    if(tre[p].l >= l && tre[p].r <= r)
        return tre[p].sum;
    int ans = 0;
    if(tre[lch(p)].r >= l)
        ans += query(lch(p), l, r);
    if(tre[rch(p)].l <= r)
        ans += query(rch(p), l, r);
    return ans;
}
void add(int p, int idx, int k){
    if(tre[p].l == tre[p].r){
        tre[p].sum += k;
        return ;
    }
    if(idx <= tre[lch(p)].r)
        add(lch(p), idx, k);
    else
        add(rch(p), idx, k);
    update(p);
}
int main(){
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    int kase = 1;
    while(T --){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i ++)
            cin>>a[i];
        build(1, 1, n);
        cout<<"Case "<<kase ++<<":"<<endl;
        while(true){
            string cmd;
            cin>>cmd;
            if(cmd == "Query"){
                int a, b;
                cin>>a>>b;
                cout<<query(1, a, b)<<endl;
            }
            if(cmd == "Add"){
                int a, b;
                cin>>a>>b;
                add(1, a, b);
            }
            if(cmd == "Sub"){
                int a, b;
                cin>>a>>b;
                add(1, a, -b);
            }
            if(cmd == "End")
                break;
        }
    }
    return 0;
}

