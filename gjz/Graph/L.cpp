#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
vector<int> g[maxn];
int pre[maxn], low[maxn], sccno[maxn], inz[maxn], otz[maxn], dtime, sccnt;
stack<int> s;
void dfs(int u){
    pre[u] = low[u] = ++dtime;
    s.push(u);
    for(int i = 0; i < g[u].size(); i ++){
        int v = g[u][i];
        if(!pre[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(!sccno[v]){
            low[u] = min(low[u], pre[v]);
        }
    }
    if(pre[u] == low[u]){
        sccnt ++;
        while(true){
            int x = s.top();
            s.pop();
            sccno[x] = sccnt;
            if(x == u)
                break;
        }
    }
}
void tarjan(int n){
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    dtime = sccnt = 0;
    for(int i = 0; i < n; i ++){
        if(!pre[i])
            dfs(i);
    }
}
int main(){
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i < n; i ++) g[i].clear();
        for(int i = 0; i < m; i ++){
            int u, v;
            cin>>u>>v;
            u --;
            v --;
            g[u].push_back(v);
        }
        tarjan(n);
        for(int i = 1; i <= sccnt; i ++)
            inz[i] = otz[i] = 1;
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < g[k].size(); i ++){
                int v = g[k][i];
                if(sccno[v] != sccno[k]){
                    inz[sccno[v]] = 0;
                    otz[sccno[k]] = 0;
                }
            }
        }
        int a = 0, b = 0;
        for(int i = 1; i <= sccnt; i ++){
            if(inz[i]) a ++;
            if(otz[i]) b ++;
        }
        int ans = max(a, b);
        if(sccnt == 1)
            ans = 0;
        cout<<ans<<endl;
    }
    return 0;
}

