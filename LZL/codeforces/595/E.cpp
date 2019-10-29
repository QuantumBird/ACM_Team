#include<bits/stdc++.h>
using namespace std;
//不错的一道最短路 建图也是一种技巧
//这题大佬都是拿dp写的

using pa = pair<int,int>;
const int maxn = 200000*3+20;
const int INF = 0x3f3f3f3f;
int dis[maxn];
int n,c,tmp;
struct edge{
    int from,to;
    int w;
};
vector<vector<edge>>G(maxn);

int Dijkstra(){
    priority_queue<pa,vector<pa>,greater<pa> >que;
    fill(dis,dis+maxn,INF);
    dis[1+2*n] = 0;
    que.emplace(make_pair(0,1+2*n));
    while(!que.empty()){
        pa temp = que.top();
        que.pop();
        int u = temp.first;
        int v = temp.second;
        if(dis[v] < u) continue;
        for(auto x : G[v]){
            if(u + x.w < dis[x.to]){
                dis[x.to] = u + x.w;
                que.emplace(make_pair(dis[x.to],x.to));
            }
        }
    }
}

void add(int from,int to,int tmp){
    G[from].push_back({from,to,tmp});
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> c;
    for(int i=1;i<n;++i){//楼梯
        cin >> tmp;
        add(i,i+1,tmp);
    }
    for(int i=1;i<n;++i){//电梯
        cin >> tmp;
        add(i+n,i+n+1,tmp);
    }
    for(int i=1;i<=n;++i){
        add(i,i+2*n,0);
        add(i+2*n,i,0);

        add(i+2*n,i+n,c);
        add(i+n,i+2*n,0);
    }
    Dijkstra();
    for(int i=1;i<=n;++i){
        cout << dis[i+2*n] << " ";
    }
    return 0;
}