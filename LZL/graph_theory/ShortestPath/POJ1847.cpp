//这道题给我一个思路　对于边权有优先级的情况　可以从图的权值为零入手
//参考超级源点
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
using namespace std;

using pa = pair<int,int>;
int m,n;
int tmpa,tmpb,tmpc;
size_t ans;
struct node{
    int to,w;
};
const int maxn = 105;
const int INF = 0x3f3f3f3f;
vector<node> G[maxn];
int dis[maxn];

void Dijkstra(){
    priority_queue<pa,vector<pa>,greater<pa> >que;
    fill(dis,dis+maxn,INF);
    que.push(make_pair(0,tmpa));
    dis[tmpa] = 0;
    while(!que.empty()){
        pa temp = que.top();
        que.pop();
        int u = temp.first;
        int v = temp.second;
        if(dis[v] < u) continue;
        std::size_t len = G[v].size();
        for(int i=0;i<len;++i){
            node &T = G[v][i];
            if(dis[v] + T.w < dis[T.to]){
                dis[T.to] = dis[v] + T.w;
                que.push(make_pair(dis[T.to],T.to));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m >> tmpa >> tmpb;
    for(int i=1;i<=m;++i){
        cin >> n;
        for(int j=0;j<n;++j){
            cin >> tmpc;
            if(!j) G[i].push_back({tmpc,0});
            else G[i].push_back({tmpc,1});
        }
    }
    Dijkstra();
    if(dis[tmpb] == INF ) cout << -1 << endl;
    else cout << dis[tmpb] << endl;
    return 0;
}