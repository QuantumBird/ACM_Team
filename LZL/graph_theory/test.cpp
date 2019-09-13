#include <iostream>
using namespace std;
#define maxn 105
int n,dfn[maxn],low[maxn],tim = 0,num = 0,size[maxn],id[maxn];
bool in[maxn];
#include <vector>
vector<int>map[maxn];
#include <stack>
stack<int>s;
#include <cstring>
#define cl(a,b) memset(a,b,sizeof(a))

void tarjan(int u){
    in[u] = 1;
    s.push(u);
    dfn[u] = low[u] = tim++;
    for (int i = 0; i < map[u].size(); i++) {
        if (dfn[map[u][i]] == -1) {
            tarjan(map[u][i]);
            low[u] = min(low[u],low[map[u][i]]);
        }else if(in[map[u][i]]) low[u] = min(low[u],dfn[map[u][i]]);
    }
    if (dfn[u] == low[u]) {
        int v;
        for(int v; 1; )
        {
            v=s.top();s.pop();in[v]=0;
            id[v]=num;//缩点过程
            size[num]++;
            if(v==u) break;
        }
        num++;
    }
}

int main() {
    scanf("%d",&n);
    for (int u = 1,v; u <= n; u++) {
        map[u].clear();
        while (scanf("%d",&v) && v) map[u].push_back(v);
    }
    while (!s.empty()) s.pop();cl(in, 0);cl(dfn, -1);

    for (int u = 1; u <= n; u++) //防止有多个图
        if (dfn[u] == -1) tarjan(u);

    for (int i = 0; i < num; i++) dfn[i] = low[i] = 0;
    
    for (int u = 1; u <= n ; u++)
        for (int j = 0; j < map[u].size(); j++)
            if (id[u] != id[map[u][j]]) {dfn[id[u]]++;low[id[map[u][j]]]++;}
                                        //dfn 出度　　low入度
    int ans1 = 0,ans2 = 0;
    for (int i = 0; i < num; i++){
        if (low[i] == 0) ans1++;
        if (dfn[i] == 0) ans2++;
    }
    ans2 = max(ans2,ans1);
    if (num == 1) {ans1 = 1;ans2 = 0;}
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
