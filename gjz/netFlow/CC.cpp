#include <bits/stdc++.h>
using namespace std;
const int MAX_NODE = 4e4 + 4;
const int MAX_EDGE = 5e5 + 5;
const int INF = INT_MAX;
template<typename T>
class Edge{
public:
    int u, v;
    T cap, flow;
    Edge(){}
    Edge(int u, int v, T cap, T flow):
    u(u), v(v), cap(cap), flow(flow){}
};

template<typename T>
class Dinic{
public:
    int n, m, s, t;
    Edge<T> edges[MAX_EDGE];
    int first[MAX_NODE];
    int next[MAX_NODE];
    bool vis[MAX_NODE];
    T d[MAX_NODE];
    int cur[MAX_NODE];
    vector<int> cut;

    void init(int n){
        this->n = n;
        memset(first, -1, sizeof(first));
        this->m = 0;
    }
    void add_Edge(int u, int v, T cap){
        edges[m] = Edge<T>(u, v, cap, 0);
        next[m] = first[u];
        first[u] = m ++;
        edges[m] = Edge<T>(v, u, 0, 0);
        next[m] = first[v];
        first[v] = m ++;
    }
    bool bfs(){
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(int i = first[u]; i != -1; i = next[i]){
                Edge<T> e = edges[i];
				if (!vis[e.v] && e.cap > e.flow) {
					vis[e.v] = true;
					d[e.v] = d[u] + 1;
					Q.push(e.v);
				}
            }
        }
        return vis[t];
    }
	T dfs(int u, T a){
		if (u == t || a == 0) return a;
		T flow = 0, f;
		for (int &i = cur[u]; i != -1; i = next[i]) {
			Edge<T>& e = edges[i];
			if (d[u] + 1 == d[e.v] && (f = dfs(e.v, min(a, e.cap - e.flow))) > 0) {
				e.flow += f;
				edges[i^1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
    }
	T Maxflow(int s, int t){
		this->s = s; this->t = t;
		T flow = 0;
		while (bfs()) {
			for (int i = 0; i < n; i++)
				cur[i] = first[i];
			flow += dfs(s, INF);
		}
		return flow;
	}
	void MinCut(){
		cut.clear();
		for (int i = 0; i < m; i += 2) {
			if (vis[edges[i].u] && !vis[edges[i].v])
				cut.push_back(i);
		}
	}
};
const int MAXN = 400;
const int movx[] = {1, -1, 0, 0};
const int movy[] = {0, 0, -1, 1};
int n, m;
int g[MAXN][MAXN];
Dinic<long long> solver;
int main(){
    int kase = 0;
    while(cin>>n>>m){
        solver.init(n*m + 2);
        int s = n*m, t = n*m + 1;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                cin>>g[i][j];
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(g[i][j] == 1) solver.add_Edge(s, i*m + j, INF);
                if(g[i][j] == 2) solver.add_Edge(i*m + j, t, INF);
                for(int k = 0; k < 4; k ++){
                    int tx = i + movx[k];
                    int ty = j + movy[k];
                    if(tx >= 0 && tx < n && ty >= 0 && ty < m)
                        solver.add_Edge(i*m + j, tx*m + ty, 1);
                }
            }
        }
        cout<<"Case "<< ++kase<<":"<<endl;
        cout<<solver.Maxflow(s, t)<<endl;
    }
    return 0;
}