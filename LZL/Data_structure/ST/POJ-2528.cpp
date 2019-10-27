//离散化+区间修改
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
int book[maxn<<1];
int segt[maxn<<2];
int lazy[maxn<<2];
bool flag[maxn<<2];
int ll[maxn];
int rr[maxn];
int ans;
int m,T,tmpa,tmpb;

void init(){
    memset(book,0,sizeof(book));
    memset(segt,0,sizeof(segt));
    memset(lazy,0,sizeof(lazy));
    memset(flag,0,sizeof(flag));
    ans = 0;
}

int BS(int q,vector<int> &vec){
    return lower_bound(vec.begin(),vec.end(),q) - vec.begin() + 1;
}

void push_down(int q){
    if(lazy[q] != 0){
        lazy[lson] = lazy[rson] = lazy[q];
        lazy[q] = 0;
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l >= lhs && r <= rhs){
        lazy[q] = k;
        return;
    }
    int m = mid;
    push_down(q);
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs >  m) update(rson,m+1,r,lhs,rhs,k);
}

void query(int q,int l,int r){
    if(lazy[q] != 0){
        if(!flag[lazy[q]]){
            ++ans;
            flag[lazy[q]] = true;
        }
        return;
    }
    if(l == r) return; //假设l和r没有被染色
    int m = mid;
    query(lson,l,m);
    query(rson,m+1,r);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> T;
    vector<int>vec;
    while(T--){
        init();
        cin >> m;
        int sum = 0;
        for(int i=1;i<=m;++i){
            cin >> ll[i] >> rr[i];
            vec.push_back(ll[i]);
            vec.push_back(rr[i]);
        }   
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        std::size_t len = vec.size();
        for(int i=1;i<len;++i){
            if(vec[i] - vec[i-1] > 1){
                vec.push_back(vec[i-1] + 1);
            }
        }
        sort(vec.begin(),vec.end());
        len = vec.size();
        for(int i=1;i<=m;++i){
            update(1,1,len,BS(ll[i],vec),BS(rr[i],vec),i);
        }
        query(1,1,len);
        cout << ans << endl;
    }
    return 0;
}