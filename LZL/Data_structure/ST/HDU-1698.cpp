#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
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
const int maxn = 100000+10;
int book[maxn];
int segt[maxn<<2];
int lazy[maxn<<2];
int Len[maxn<<2];
int T,m,n;
int tmpa,tmpb,tmpc;
int flag;

int push_up(int q){
    segt[q] = segt[lson] + segt[rson];
}

void init(){
    memset(book,0,sizeof(book));
    memset(segt,0,sizeof(segt));
    memset(lazy,0,sizeof(lazy));
    memset(Len,0,sizeof(Len));
}


void build(int q,int l,int r){
    Len[q] = r-l+1;
    if(l == r){
        segt[q] = 1;
        return;
    } 
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void push_down(int q){
    if(lazy[q]){
        lazy[lson] = lazy[rson] = lazy[q];
        segt[lson] = Len[lson]*lazy[q];
        segt[rson] = Len[rson]*lazy[q];
        lazy[q] = 0;
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        lazy[q] = k;
        segt[q] = Len[q]*k;
        return;
    }
    int m = mid;
    push_down(q);
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs  > m) update(rson,m+1,r,lhs,rhs,k);
    push_up(q);
}

int query(int q,int l,int r,int lhs,int rhs){
    if(l>=lhs && r<=rhs){
        return segt[q];
    }
    int m = mid;
    int ans = 0;
    if(lhs <= m) ans += query(lson,l,m,lhs,rhs);
    if(rhs  > m) ans += query(rson,m+1,r,lhs,rhs);
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        init();
        cin >> m >> n;
        build(1,1,m);
        for(int i=0;i<n;++i){
            cin >> tmpa >> tmpb >> tmpc;
            update(1,1,m,tmpa,tmpb,tmpc);
        }
        cout << "Case "<< ++flag << ": The total value of the hook is "<< segt[1] <<".\n";
    }
    return 0;
}