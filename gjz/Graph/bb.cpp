#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;

typedef pair<int, int> P;

struct edge{
    int to, dist;
    edge(int t, int d):
       to(t), dist(d){};
};

vector<edge> g[maxn];
map<string, int> name;
int n;

int dijkstra(int st, int ed){
    int dis[maxn];
    fill(dis, dis + n + 1, inf);
    priority_queue<P, vector<P>, greater<P> > que;
    dis[st] = 0;
    que.push(P(0, st));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dis[v] < p.first)
            continue;
        for(int i = 0; i < g[v].size(); i ++){
            edge e = g[v][i];
            if(dis[e.to] > dis[v] + e.dist){
                dis[e.to] = dis[v] + e.dist;
                que.push(P(dis[e.to], e.to));
            }
        }
    }
    return dis[ed];
}

int main(){
    string s, e, st, ed;
    int dst;
    while(cin>>n, n != -1){
        name.clear();
        for(int i = 0; i < maxn; i ++)
            g[i].clear();
        int cnt = 1;
        cin>>st>>ed;
        name[st] = cnt ++;
        name[ed] = cnt ++;
        for(int i = 0; i < n; i ++){
            cin>>s>>e>>dst;
            if(!name[s]) name[s] = cnt ++;
            if(!name[e]) name[e] = cnt ++;
            g[name[s]].push_back(edge(name[e], dst));
            g[name[e]].push_back(edge(name[s], dst));
        }
        int ans = dijkstra(name[st], name[ed]);
        if(ans < inf)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}

