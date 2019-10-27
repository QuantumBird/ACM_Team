#include <iostream>
#include <string>
using namespace std;
const int maxn = 5e4 + 1;
int a[maxn];
struct Node{
    int l, r, sum;
};
Node st[maxn << 2];
void pushup(int idx){
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
    pushup(idx);
}
void add(int idx, int pos, int diff){
    if(st[idx].l == st[idx].r){
        st[idx].sum += diff;
        return ;
    }
    int mid = (st[idx].l + st[idx].r) / 2;
    if(pos <= mid)
        add(idx << 1, pos, diff);
    else
        add(idx << 1 | 1, pos, diff);
    pushup(idx);
}
int query(int idx, int s, int t){
    if(st[idx].l >= s && st[idx].r <= t) return st[idx].sum;
    int mid = (st[idx].l + st[idx].r) / 2;
    int ans = 0;
    if(t > mid)
        ans += query(idx << 1 | 1, s, t);
    else
        ans += query(idx << 1, s, t);
    return ans;
}
int main(){
    int T, kase = 0;
    cin>>T;
    while(T --){
        int n;
        cin>>n;
        for(int i = 1; i <= n; i ++) cin>>a[i];
        build(1, 1, n);
        cout<<"Case "<<++ kase<<":"<<endl;
        string s;
        while(cin>>s, s != "End"){
            switch(s[0]){
                case 'Q':{
                    int s, t;
                    cin>>s>>t;
                    cout<<query(1, s, t)<<endl;
                }; break;
                case 'A':{
                    int i, d;
                    cin>>i>>d;
                    add(1, i, d);
                }; break;
                case 'S':{
                    int i, d;
                    cin>>i>>d;
                    add(1, i, -d);
                }; break;
            }
        }
    }
    return 0;
}
