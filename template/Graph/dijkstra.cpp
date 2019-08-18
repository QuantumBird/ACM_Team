#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX
const int maxn = 1e5 + 10;

struct edge{
    int to, dist;
    edge(int t, int d): 
        to(t), dist(d) {}
};
vector<edge> g[maxn];

bool vis[maxn];
int dis[maxn];
int pre[maxn];

int vn, en;

void init(){
    vn = en = 0;
    fill(vis, vis + maxn, true);
    fill(dis, dis + maxn, INF);
    fill(pre, pre + maxn, -1);
    for(int i = 0; i < maxn; i ++)
        g[i].clear();
}

void dijkstra(int s){
    dis[s] = 0;
    pre[s] = s;
    for(int i = 0; i < vn; i ++){
        int u = -1, mind = INF;
        for(int j = 0; j < vn; j ++){
            if(vis[j] && dis[j] < mind){
                u = j;
                mind = dis[j];
            }
        }
        if(u == -1)
            return ;
        vis[u] = false;
        for(int j = 0; j < g[u].size(); j ++){
            int t = g[u][j].to;
            if(vis[t]){
                if(dis[u] + g[u][j].dist < dis[t]){
                    dis[t] = dis[u] + g[u][j].dist;
                    pre[t] = u;
                }
            }
        }
    }
}

int main(){
    init();
    cout<<"INIT CMPL"<<endl;
    return 0;
}

