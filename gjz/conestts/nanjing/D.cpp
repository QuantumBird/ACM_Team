#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5 + 1;
vector<int> g[maxn];
double E[maxn];
bool vis[maxn];
int arrive[maxn];
double trans[maxn];
int n, m;
void init(){
    for(int i = 0; i < maxn; i ++)
        g[i].clear();
    memset(E, 0, sizeof(E));
    memset(vis, false, sizeof(vis));
}
void input(){
    cin>>n>>m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
void bfs(){
    int s = 1, t = n;
    int p = g[s].size() + 1;
    E[s] = 1.0 / (p*(1 - p));
    trans[s] = 1.0 / p;
    queue<int> que;
    vis[s] = true;
    arrive[s] = 0;
    for(int i = 0; i < g[s].size(); i ++)
        if(vis[g[s][i]] == false){
            que.push(g[s][i]);
            arrive[g[s][i]] = arrive[s] + 1;
        }
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        double ansE = 0;
        int cntp = 0;
        for(int i = 0; i < g[tmp].size(); i ++){
            if(vis[g[tmp][i]] == true){
                ansE += (arrive[g[tmp][i]] + E[g[tmp][i]]) * trans[g[tmp][i]];
            }else{
                cntp ++;
            }
        }
        E[tmp] = ansE + 1.0 / (1 + cntp);
        trans[tmp] = 1.0 / (1 + cntp);
        vis[tmp] = true;
        for(int i = 0; i < g[tmp].size(); i ++){
            if(vis[g[tmp][i]] == false){
                arrive[g[tmp][i]] = arrive[tmp] + 1;
                que.push(g[tmp][i]);
            }
        }
    }
}
double get_ans(){
    return E[n];
}
int main(){
    int T;
    cin>>T;
    while(T --){
        init();
        input();
        bfs();
        cout<<get_ans()<<endl;
    }
    return 0;
}
