//这个题的转化很有意思
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

//using pa = pair<int,int>;
typedef pair<int,int> pa;
int m,n,q;
int tmpa,tmpb,tmpc;
int flag;
long long ans;
struct node{
    int to,w;
};
const int maxn = 50000+10;
const int INF = 9999999999999;
vector<node> G[maxn];
long long dis[maxn];
int weight[maxn];

void Dijkstra(){
    priority_queue<pa,vector<pa>,greater<pa> > que;
    fill(dis,dis+maxn,INF);
    dis[1] = 0;
    que.push(make_pair(0,1));
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
    cin >> q;
    while(q--){
        flag = 0;
        ans = 0;
        for(int i=0;i<maxn;++i) G[i].clear();
        cin >> m >> n;
        for(int i=1;i<=m;++i){
            cin >> weight[i];
        }
        for(int i=1;i<=n;++i){
            cin >> tmpa >> tmpb >> tmpc;
            G[tmpa].push_back({tmpb,tmpc});
            G[tmpb].push_back({tmpa,tmpc});
        }
        Dijkstra();
        for(int i=1;i<=m;++i){
            if(dis[i] == INF) flag = 1;
            ans += dis[i]*weight[i];
        }
        if(flag) cout << "No Answer\n";
        else cout << ans << endl;
    }
    return 0;
}