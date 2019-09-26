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

struct node{
    int w,to;
};
vector<node>G[1010];
typedef pair<int,int> pa;
int q,m,n;
int tmpa,tmpb,tmpc;
int dis[1010];
int p[1010];
const int INF = 0x3f3f3f3f;

int Dijkstra(int from){
    priority_queue<pa,vector<pa>,greater<pa>>que;
    fill(dis,dis+1005,INF);
    dis[from] = 0;
    que.emplace(make_pair(from,0));
    while(!que.empty()){
        pa p = que.top();
        que.pop();
        int v = p.second;
        if(dis[p.first] < v) continue;
        for(auto x : G[p.first]){
            if(dis[p.first]+x.w<dis[x.to]){
                dis[x.to] = dis[p.first]+x.w;
                que.emplace(make_pair(x.to,dis[x.to]));
            }
        }
    }
}

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&n);
        for(int i=0;i<n;++i){
            scanf("%d %d %d",&tmpa,&tmpb,&tmpc);
            node tmp = {tmpb,tmpc};//这次不要忘了
            G[tmpa].emplace_back(tmp);
        }
        scanf("%d %d",&tmpa,&tmpb);
        Dijkstra(tmpa);
    }
}