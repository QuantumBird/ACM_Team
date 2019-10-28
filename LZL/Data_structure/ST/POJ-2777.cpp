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
const int INF = 2147483647;
int L,T,O;
int segt[maxn<<2];
int lazy[maxn<<2];
int book[40];
char ch;
int lhs,rhs,w;

int judge(int x){ //可判断一个二进制有多少个1 值得到做一个板子
    return x == 0 ? 0 : judge(x>>1) + (x&1);
}

void push_up(int q){
    segt[q] = segt[lson] | segt[rson];
}

void build(int q,int l,int r){
    if(l == r){
        segt[q] = 2;
        return;
    }
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void push_down(int q){
    if(lazy[q]){
        segt[lson] = lazy[q];
        segt[rson] = lazy[q]; 
        lazy[lson] = lazy[rson] = lazy[q];
        lazy[q] = 0; 
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        segt[q] = k;
        lazy[q] = k;
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
    push_down(q);
    int ans = 0;
    int m = mid;
    if(lhs <= m) ans |= query(lson,l,m,lhs,rhs);
    if(rhs  > m) ans |= query(rson,m+1,r,lhs,rhs);
    push_up(q);
    return ans;
}

int main(){
    for(int i=0;i<=31;++i){
        book[i] = pow(2,i);
    }
    std::ios::sync_with_stdio(false);
    cin >> L >> T >> O;
    build(1,1,L);   
    for(int i=0;i<O;++i){
        cin >> ch;
        if(ch == 'C'){
            cin >> lhs >> rhs >> w;
            update(1,1,L,lhs,rhs,book[w]);
        }else{
            cin >> lhs >> rhs;
            cout << judge(query(1,1,L,lhs,rhs)) << endl;
        }
    }
    return 0;
}