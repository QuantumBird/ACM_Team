//线段树上二分
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
const int maxn = 100000+10;

int segt[maxn<<2];
int book[maxn];
int len[maxn<<2];
int lazy[maxn<<2];
int T,m,n,A,F,B;

int init(){
    memset(segt,0,sizeof(segt));
    memset(book,0,sizeof(book));
    memset(len,0,sizeof(len));
    memset(lazy,0,sizeof(lazy));
}

void push_up(int q){
    segt[q] = segt[lson] + segt[rson];
}

void build(int q,int l,int r){
    len[q] = r-l+1;
    lazy[q] = -1;
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
    if(lazy[q] != -1){
        lazy[lson] = lazy[rson] = lazy[q];
        segt[lson] = len[lson]*lazy[q];
        segt[rson] = len[rson]*lazy[q];
        lazy[q] = -1;
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        lazy[q] = k;
        segt[q] = len[q]*k;
        return;
    }
    push_down(q);
    int m = mid;
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
    push_down(q);
    if(lhs <= m) ans+=query(lson,l,m,lhs,rhs);
    if(rhs  > m) ans+=query(rson,m+1,r,lhs,rhs);
    return ans;
}

int find_lift(int l){
    int r = m;
    while(l < r){
        int MID = (l+r)>>1;
        if(query(1,1,m,l,MID) >= 1) r = MID;
        else l = MID+1;
    }
    return r;
}

int find_right(int ll,int B){
    int l = ll, r = m;
    while(l < r){
        int MID = (l+r)>>1;
        if(query(1,1,m,ll,MID) >= B) r = MID; //二分这里面的其实参数不变是精髓　这很重要
        else l = MID + 1;
    }
    return r;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        init();
        cin >> m >> n;
        build(1,1,m);
        for(int i=0;i<n;++i){
            cin >> F >> A >> B;
            if(F == 1){
                ++A;
                int sum = query(1,1,m,A,m);
                if(sum == 0){
                    cout << "Can not put any one.\n";
                    continue;
                }
                int lift = find_lift(A);
                int right = find_right(lift,min(sum,B));
                cout << lift-1 << " " << right-1 << endl;
                update(1,1,m,lift,right,0);
            }else{
                ++A,++B;
                cout << (B-A+1) - query(1,1,m,A,B) << endl;
                update(1,1,m,A,B,1);
            }
        }
        cout << endl;
    } 
    return 0;
}