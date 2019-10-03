//这种写法求得是最短路与次短路　以及真最短路数量(第一题长度为7有两条路　但没有边相交)
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

namespace{
    struct node{
        int w,to;
    };
    vector<node>G[1010];
    typedef pair<int,int> pa;
    int q,m,n;
    int tmpa,tmpb,tmpc;
    int dis[1010][2];//0为最短路　1为次短路
    int Count[1010][2];//0为最短路数量　1次短路数量　
    const int INF = 0x3f3f3f3f;
}

void init(){
    for(int i=0;i<1005;++i){
        for(int j=0;j<2;++j){
            dis[i][j] = INF;}}
    for(int i=0;i<1005;++i){
        for(int j=0;j<2;++j){
            Count[i][j] = 0;}}
}

int Dijkstra(int from){
    priority_queue<pa,vector<pa>,greater<pa>>que;
    init();
    Count[from][0] = 1;
    Count[from][1] = 1;
    dis[from][0] = 0;
    dis[from][1] = INF;
    que.emplace(make_pair(0,from));
    while(!que.empty()){
        pa p = que.top();
        que.pop();
        for(auto x : G[p.second]){
            if(dis[p.second][0]+x.w<dis[x.to][0]){
                dis[x.to][0] = dis[p.second][0]+x.w;
                Count[x.to][0] = Count[p.second][0];
                que.emplace(make_pair(dis[x.to][0],x.to));
            }else if(dis[p.second][0]+x.w == dis[x.to][0]){//新路径等于最短路　更新最短路径条数
                Count[x.to][0]+=1;
            }else if(dis[p.second][0]+x.w < dis[x.to][1] && dis[p.first][0]+x.w > dis[x.to][0]){
                    //大于最短路　短于次短路 更新次短路
                dis[x.to][1] = dis[p.second][0]+x.w;
                Count[x.to][1] = Count[p.second][0];
                //应对多重边的情况
            }else if(dis[p.second][0]+x.w == dis[x.to][1]){
                //cout << dis[p.second][0] << " "<<p.second <<" "  <<x.to << endl;
                Count[x.to][1]+=1;
            }
        }
    }
}

int main(){
    scanf("%d",&q);
    while(q--){
        for(int i=0;i<1005;++i) G[i].clear();
        scanf("%d %d",&m,&n);
        for(int i=0;i<n;++i){
            scanf("%d %d %d",&tmpa,&tmpb,&tmpc);
            node tmp = {tmpc,tmpb};
            G[tmpa].emplace_back(std::move(tmp));
        }
        scanf("%d %d",&tmpa,&tmpb);
        Dijkstra(tmpa);
        if(abs(dis[tmpb][0]-dis[tmpb][1])==1){
            printf("%d\n",Count[tmpb][0]+Count[tmpb][1]);
        }else{
            printf("%d\n",Count[tmpb][0]);
        }
    }
    return 0;
}