#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <climits>
using namespace std;
const int maxn = 1e4 + 10;
int dis[maxn];
bool vis[maxn];
struct Edge{
    int to, dist;
    Edge(int t, int d):
        to(t), dist(d){}
};
vector<Edge> g[maxn];
int vn;

int main(){
    int t;
    while(cin>>t, t != -1){
        fill(dis, dis + maxn, INT_MAX);
        fill(vis, vis + maxn, true);
        for(int i = 0; i < maxn; i ++)
            g[i].clear();
        string s, t;
        map<string, int> dict;
        cin>>s>>t;
        dict[s] = 0;
        dict[t] = 1;
        vn = 2;
        for(int m = 1; m <= t; m ++){
            int d;
            cin>>s>>t>>d;
            int is, it;
            is = (dict.find(s) == dict.end()?\
                    dict[s] = vn ++: dict[s]);
            it = (dict.find(t) == dict.end()?\
                    dict[t] = vn ++: dict[t]);
            g[is].push_back(Edge(it, d));
            g[it].push_back(Edge(is, d));
        }
        dis[0] = 0;
        for(int i = 0; i < vn; i ++){
            int u = -1, mind = INT_MAX;
            for(int j = 0; j < vn; j ++){
                if(vis[j] && dis[j] < mind){
                    u = j;
                    mind = dis[j];
                }
            }
            if(u == -1)
                break;
            vis[u] = false;
            for(int j = 0; j < g[u].size(); j ++){
                int t = g[u][j].to;
                if(vis[t]){
                    if(dis[u] + g[u][j].dist < dis[t]){
                        dis[t] = dis[u] + g[u][j].dist;
                    }
                }
            }
        }
        if(dis[2] < INT_MAX)
            cout<<dis[2]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}

    
