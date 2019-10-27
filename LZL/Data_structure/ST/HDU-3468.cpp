#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
const int maxn = 100000+10;
typedef long long ll;
ll book[maxn];
ll segt[maxn<<2];
ll lazy[maxn<<2];
ll len[maxn<<2];
ll m,n,tmpa,tmpb,tmpc;
char ch;

void init(){
    memset(book,0,sizeof(book));
    memset(segt,0,sizeof(segt));
    memset(lazy,0,sizeof(lazy));
    memset(len,0,sizeof(len));
}

void push_up(ll q){
    segt[q] = segt[lson] + segt[rson];
    
}

void build(ll q,ll l,ll r){
    len[q] = r-l+1;
    if(l == r){
        segt[q] = book[l];
        return;
    }
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void push_down(ll q){
    if(!lazy[q]) return;
    lazy[lson] += lazy[q];
    lazy[rson] += lazy[q];
    segt[lson] += lazy[q]*len[lson];
    segt[rson] += lazy[q]*len[rson];
    lazy[q] = 0;
}

void update(ll q,ll l,ll r,ll lhs,ll rhs,ll k){
    if(l >= lhs && r<= rhs){
        segt[q] += len[q]*k;
        lazy[q] += k;
        return;
    }
    push_down(q);
    int m = mid;
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs >  m) update(rson,m+1,r,lhs,rhs,k);
    push_up(q);
}

ll query(ll q,ll l,ll r,ll lhs,ll rhs){
    if(l>=lhs && r<=rhs){
        return segt[q];
    }
    push_down(q);
    ll sum = 0;
    ll m = mid;
    if(lhs <= m) sum += query(lson,l,m,lhs,rhs);
    if(rhs >  m) sum += query(rson,m+1,r,lhs,rhs);
    return sum;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    init();
    for(int i=1;i<=m;++i){
        cin >> book[i];
    }
    build(1,1,m);
    while(n--){
        cin >> ch >> tmpa >> tmpb;
        if(ch == 'C'){
            cin >> tmpc;
            update(1,1,m,tmpa,tmpb,tmpc);
        }else{
            cout << query(1,1,m,tmpa,tmpb) << endl;
        }
    }
    return 0;
}