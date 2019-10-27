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
const int maxn = 200000+10;
const int INF = 0x3f3f3f3f;

struct node{
    int MAX,MIN;
};

node segt[maxn<<2];
int book[maxn];

int m,n;
int tmpa,tmpb;

void push_up(int q){
    segt[q].MAX = max(segt[lson].MAX,segt[rson].MAX);
    segt[q].MIN = min(segt[lson].MIN,segt[rson].MIN);
}

void build(int q,int l,int r){
    if(l == r){
        segt[q].MAX = segt[q].MIN = book[l];
        return;
    }
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

int query_max(int q,int l,int r,int lhs,int rhs){
    if(l>=lhs && r<=rhs){
        return segt[q].MAX;
    }
    int m = mid;
    int ans = 0;
    if(lhs <= m) ans = max(query_max(lson,l,m,lhs,rhs),ans);
    if(rhs  > m) ans = max(query_max(rson,m+1,r,lhs,rhs),ans);
    return ans;
}

int query_min(int q,int l,int r,int lhs,int rhs){
    if(l>=lhs && r<=rhs){
        return segt[q].MIN;
    }
    int m = mid;
    int ans =INF ;
    if(lhs <= m) ans = min(query_min(lson,l,m,lhs,rhs),ans);
    if(rhs  > m) ans = min(query_min(rson,m+1,r,lhs,rhs),ans);
    return ans;
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;++i){
        scanf("%d",&book[i]);
    }
    build(1,1,m);
    for(int i=0;i<n;++i){
        scanf("%d %d",&tmpa,&tmpb);
        printf("%d\n",query_max(1,1,m,tmpa,tmpb)-query_min(1,1,m,tmpa,tmpb));
    }
    return 0;
}