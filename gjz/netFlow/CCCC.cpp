#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 10010
#define maxm 100010
#define inf 0x7fffffff

using namespace std;

int n,m,s,t;
int sum,ans;
int d[maxn];

struct edge{
    int to,val,rev; 
    edge (int _to,int _val,int _rev){
        to=_to;
        val=_val;
        rev=_rev;
    }
};

vector<edge> e[maxn];

void addedge(int x,int y,int w){
    e[x].push_back(edge(y,w,e[y].size()));
    e[y].push_back(edge(x,0,e[x].size()-1));
}

bool bfs(){
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++){
            int y=e[x][i].to;
            if(d[y]==-1 && e[x][i].val){
                q.push(y);
                d[y]=d[x]+1;
            }
        }
    }
    if(d[t]==-1)
        return 0;
    else
        return 1;
}

int dfs(int x,int low){
    if(x == t || low == 0)
        return low;
    int totflow = 0;
    for(int i = 0;i < e[x].size(); i++){
        int y = e[x][i].to;
        int rev = e[x][i].rev;
        if(d[y] == d[x] + 1 && e[x][i].val){
            int a = dfs(y, min(low, e[x][i].val));
            e[x][i].val -= a;
            e[y][rev].val += a;
            low -= a;
            totflow += a;
            if(low == 0) 
                return totflow;
        }
    }
    if(low!=0) 
        d[x]=-1;
    return totflow;
}

void dinic(){
    while(bfs())
        ans += dfs(s, inf);
}
const int maxt = 400;
int g[maxt][maxt];
const int movx[] = {1, -1, 0, 0};
const int movy[] = {0, 0, -1, 1};
int main(){
    int kase = 0, N, M;
    while(cin>>N>>M){
        n = N*M + 2;
        for(int i = 0; i < maxn; i ++) e[i].clear();
        s = N*M; t = N*M + 1;
        for(int i = 0; i < N; i ++)
            for(int j = 0; j < M; j ++)
                cin>>g[i][j];
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < M; j ++){
                if(g[i][j] == 1) addedge(s, i*m + j, inf);
                if(g[i][j] == 2) addedge(i*m + j, t, inf);
                for(int k = 0; k < 4; k ++){
                    int tx = i + movx[k];
                    int ty = j + movy[k];
                    if(tx >= 0 && tx < n && ty >= 0 && ty < m)
                        addedge(i*m + j, tx*m + ty, 1);
                }
            }
        }
        dinic();
        cout<<"Case "<<++ kase<<":"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

