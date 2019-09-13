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
