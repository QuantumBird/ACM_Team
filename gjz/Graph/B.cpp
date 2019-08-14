#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <climits>
using namespace std;
const int maxn = 1e5 + 10;
map<string, int> dict;
int vn, en;
int dis[maxn];
bool vis[maxn];
struct edge{
    int to;
    int distance;
    edge(int t, int d): to(t), distance(d){}
};
vector<edge> g[maxn];
bool input(){
    vn = 0;
    cin>>en;
    if(en == -1)
        return false;
    memset(vis, true, sizeof(vis));
    for(int i = 0; i < maxn; i ++)
        dis[i] = INT_MAX;
    string s, t;
    cin>>s>>t;
    dict[s] = vn ++;
    dict[t] = vn ++;
    for(int i = 0; i < en; i ++){
        int d;
        cin>>s>>t>>d;
        int is, it;
        is = (dict.find(s) == dict.end())?\
             dict[s] = vn ++: dict[s];
        it = (dict.find(t) == dict.end())?\
             dict[t] = vn ++: dict[t];
        g[is].push_back(edge(it, d));
        g[it].push_back(edge(is, d));
    }
    return true;
}
/*
void dijkstra(int s){
    dis[s] = 0;
    vis[s] = false;
    for(int i = 0; i < vn; i ++){
        int u = -1, mind = INT_MAX;
        for(int j = 0; j < vn; j ++){
            if(dis[j] < mind){
                u = j;
                mind = dis[j];
            }
        }
        if(u == -1)
            return ;
        vis[u] = false;
        for(int j = 0; j < g[u].size(); j ++){
            int t = g[u][j].to;
            if(dis[u] + g[u][j].distance < dis[t])
                dis[t] = dis[u] + g[u][j].distance;
        }
    }
}
*/
void dijkstra(int s){
    for(int i = 0; i < g[s].size(); i ++){
        int t = g[s][i].to;
        dis[t] = g[s][i].distance;
    }
    dis[s] = 0;
    vis[s] = false;
    for(int i = 0; i < vn; i ++){
        int u = -1, mind = INT_MAX;
        for(int j = 0; j < vn; j ++){
            if(dis[j] < mind && vis[j]){
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
                if(dis[u] + g[u][j].distance < dis[t])
                    dis[t] = dis[u] + g[u][j].distance;
            }
        }
    }
}

int main(){
    while(input()){
//        cout<<vn<<endl;
        dijkstra(0);
        cout<<(dis[1] == INT_MAX? -1: dis[1])<<endl;
//        for(int i = 0; i < vn; i ++)
//            cout<<dis[i]<<" ";
    }
    return 0;
}

