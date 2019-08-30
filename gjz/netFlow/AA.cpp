#include <bits/stdc++.h>
using namespace std;
const int maxn = 222;
const int INF = INT_MAX;
struct Node{
    int to, cap, rev;
    Node(int t, int c, int r):
        to(t), cap(c), rev(r){}
};
class solver{
    vector<Node> g[maxn];
    bool vis[maxn];
public:
    solver(){
        for(int i = 0; i < maxn; i ++)
            g[i].clear();
    }
    void add_edge(int from, int to, int cap){
        g[from].push_back(Node(to, cap, g[to].size()));
        g[to].push_back(Node(from, 0, g[from].size()));
    }
    int dfs(int s, int t, int f){
        if(s == t) return f;
        vis[s] = true;
        for(int i = 0; i < g[s].size(); i ++){
            Node & tmp = g[s][i];
            if(vis[tmp.to] == false && tmp.cap > 0){
                int d = dfs(tmp.to, t, min(f, tmp.cap));
                if(d > 0){
                    tmp.cap -= d;
                    g[tmp.to][tmp.rev].cap += d;
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
            int f = dfs(s, t, INF);
            if(f == 0)
                return flow;
            flow += f;
        }
    }
};
int main(){
    int n, m;
    while(cin>>n>>m){
        solver s;
        for(int i = 0; i < n; i ++){
            int a, b, c;
            cin>>a>>b>>c;
            s.add_edge(a, b, c);
        }
        cout<<s.max_flow(1, m)<<endl;
    }
    return 0;
}

