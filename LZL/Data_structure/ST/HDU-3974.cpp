//遇到树型结构无从下手时可以用dfs序转化为线性问题
//基本题目描述就是与子树有关的题目　可以考虑转化为线性
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
int in[maxn];
int lazy[maxn<<2];
vector<vector<int> >G(maxn);
typedef pair<int,int> pa;
pa Start_End[maxn];
int T,m,n,lhs,rhs,w,from,to,cnt;
char ch;

void init(){
    memset(segt,0,sizeof(segt));
    memset(in,0,sizeof(in));
    memset(lazy,0,sizeof(lazy));
    memset(Start_End,0,sizeof(Start_End));
    for(int i=0;i<maxn;++i) G[i].clear();
    cnt = 0;
}

int dfs(int start){
    ++cnt;
    in[start] = 1;
    Start_End[start].first = cnt;
    std::size_t len = G[start].size();
    for(int i=0;i<len;++i){
        dfs(G[start][i]);
    }
    Start_End[start].second = cnt;
} //dfs序　记录时间戳

void build(int q,int l,int r){
    if(l == r){
        segt[q] = -1;
        return;
    }
    int  m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    segt[q] = -1;
}

void push_down(int q){
    if(lazy[q]){
        lazy[lson] = lazy[rson] = lazy[q];
        segt[lson] = segt[rson] = lazy[q];
        lazy[q] = 0;
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        lazy[q] = k;
        segt[q] = k;
        return;
    }
    int m = mid;
    push_down(q);
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs >  m) update(rson,m+1,r,lhs,rhs,k);
}

int query(int q,int l,int r,int number){
    if(l == number && r == number){
        return segt[q];
    }
    push_down(q);
    int m = mid;
    if(number <= m) return query(lson,l,m,number);
    else return query(rson,m+1,r,number);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> m;
        init();
        for(int i=0;i<m-1;++i){
            cin >> from >> to;
            G[to].push_back(from);
            in[from] = 1;
        }
        for(int i=1;i<=m;++i){
            if(!in[i]){
                dfs(i);//根节点
                break;
            }
        }
        build(1,1,m);
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> ch;
            if(ch == 'C'){
                cin >> lhs;
                cout << query(1,1,m,Start_End[lhs].first) << endl;
            }else{
                cin >> lhs >> rhs;
                int ll = Start_End[lhs].first;
                int rr = Start_End[lhs].second;
                update(1,1,m,ll,rr,rhs);
            }
        }
    }
    return 0;
}