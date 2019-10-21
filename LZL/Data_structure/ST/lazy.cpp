#include<bits/stdc++.h>
using namespace std;

#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
class ST{
    public:

void push_up(int q){
    segt[q] = segt[lson] + segt[rson];
}

void push_down(int q,int l,int r){
    int m=mid;
    segt[lson] = 
    lazy[lson] = lazy[q];
    lazy[rson] = lazy[q];
    lazy[q] = 0;
}

void build(int q,int l,int r){
    if(l==r){
        segt[q] = book[l];
        return;
    }
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void update(int q,int l,int r,int a,int b,int number){
    if(l>=a && r<=b){
        segt[q] = 
        lazy[q] += number;
        return;
    }
    int m = mid;
    if(lazy[q]) push_down(q,l,r);
    i(a<=m){
        update(lson,l,m,a,b,number);
    }
    if(b>m){
        update(rson,m+1,r,a,b,numebr);
    }
    push_up(q);
}
private:
    const int maxn = 1e5+10;
    int segt[maxn<<2];
    int book[maxn];
    int lazy[maxn];
}