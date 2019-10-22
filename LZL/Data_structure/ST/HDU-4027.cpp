#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility> 
#include<cstring>
#include<cstdio>
using namespace std;

#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int maxn = 100000+10;
const int INF = 0x3f3f3f3f3f3f3f3f;

ll segt[maxn<<2];
ll book[maxn];
bool lazy[maxn<<2];
ll m,n,Flag;
ll flag,lhs,rhs;

void push_up(ll q){
    segt[q] = segt[lson]+segt[rson];
}

void init(){
    memset(book,0,sizeof(book));
    memset(segt,0,sizeof(segt));
    memset(lazy,0,sizeof(lazy));
}

void build(ll q,ll l,ll r){
    if(l == r){
        segt[q] = book[l];
        return;
    }
    ll m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void update(ll q,ll l,ll r,ll lhs,ll rhs){
    if(l==r){
        segt[q] = sqrt(segt[q]);
        return;
    }
    if(l >= lhs && r <= rhs && segt[q] == r-l+1) return;
    //因为根号趋势下降的很快　所以可以单点更新
    ll m = mid;
    if(lhs <= m) update(lson,l,m,lhs,rhs);
    if(rhs  > m) update(rson,m+1,r,lhs,rhs);
    push_up(q);
}

ll query(ll q,ll l,ll r,ll lhs,ll rhs){
    if(l>=lhs && r<=rhs){
        return segt[q];
    }
    ll ans = 0;
    ll m = mid;
    if(lhs <= m) ans += query(lson,l,m,lhs,rhs);
    if(rhs  > m) ans += query(rson,m+1,r,lhs,rhs);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> m){
        init();
        for(int i=1;i<=m;++i){
            cin >> book[i];
        }
        build(1,1,m);
        cin >> n;
        cout << "Case #"<< ++Flag << ":\n";
        for(int i=0;i<n;++i){
            cin >> flag >> lhs >> rhs;
            if(rhs<lhs) std::swap(lhs,rhs);
            if(flag){
                cout << query(1,1,m,lhs,rhs) << endl;
            }else{
                update(1,1,m,lhs,rhs);
            }
        }
        cout << endl;//不向下兼容c语言时不要使用C系的输出函数
    }
    return 0;
}