#include<bits/stdc++.h>
using namespace std;

int F,P,C,M;
int from,to,w;
int m;
struct node{
    int to,w;
};
vector<node>G[510];
map<int,int>mp;
int dis[510];
const int INF = 0x3f3f3f3f;

void SPFA(){
    queue<int>que;
    set<int>stque;
    stque.insert(1);
    que.push(1);
    fill(dis,dis+510,INF);
    dis[1] = 0;
    while(!que.empty()){
        int T = que.front();
        que.pop();
        stque.erase(T);
//在这里可以设置一个标记为来判断负环 对于一个正权图而言　每个点最多入队n-1次　因为负数会使最短路缩小
        for(auto x : G[T]){
            if(dis[T] + x.w < dis[x.to]){
                dis[x.to] = dis[T] + x.w;
                if(stque.find(x.to) == stque.end()){
                    que.push(x.to);
                    stque.insert(x.to);
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> F >> P >> C >> M;
    for(int i=0;i<P;++i){
        cin >> from >> to >> w;
        G[from].push_back({to,w});
        G[to].push_back({from,w});
    }
    for(int i=1;i<=C;++i){
        cin >> m;
        mp[m] = i;
    }
    SPFA();
    vector<int>vec;
    for(int i=1;i<=F;++i){
        if(dis[i]<=M && mp.find(i)!=mp.end()){
            vec.emplace_back(mp[i]);
        }
    }
    cout << vec.size() << endl;
    sort(vec.begin(),vec.end());
    for(auto x : vec){
        cout << x << endl;
    }
    return 0;
}