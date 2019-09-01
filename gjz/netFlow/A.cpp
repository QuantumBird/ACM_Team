#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 1;
struct Node{
    int to;
    int cap;
    int rev;
};
vector<Node> g[maxn];
bool vis[maxn];
void append(int from, int to, int cap){
    g[from].push_back((Node){to, cap, g[to].size()});
    g[to].push_back((Node){from, 0, g[from].size()});
}
int dfs(int s, int t, int f){
    if(s == t) return f;
    vis[s] = true;
    for(int i = 0; i < g[s].size(); i ++){
        Node & tn = g[s][i];
        if(vis[tn.to] == false && tn.cap > 0){
            int d = dfs(tn.to, t, min(f, tn.cap));
            if(d > 0){
                tn.cap -= d;
                g[tn.to][tn.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t){
    int flow = 0;
    while(true){
        memset(vis, false, sizeof(vis));
        int f = dfs(s, t, INT_MAX);
        if(f == 0) return flow;
        flow += f;
    }
}
int main(){
    int n, m;
    while(cin>>n>>m){
        for(int i = 0; i < maxn; i ++) g[i].clear();
        for(int i = 0; i < n; i ++){
            int f, t, c;
            cin>>f>>t>>c;
            append(f, t, c);
        }
        cout<<max_flow(1, m)<<endl;
    }
    return 0;
}

