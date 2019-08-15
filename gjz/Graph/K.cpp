#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
struct node{
    int to, next;
} edge[maxn];
int Low[maxn], DFN[maxn];
int head[maxn];
int tot, top, stk[maxn], belong[maxn];
int scc, idx;
bool instack[maxn];
void add_edge(int u, int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot ++;
}
void init(){
    memset(head, -1, sizeof(head));
    memset(instack, false, sizeof(instack));
    memset(DFN, 0, sizeof(DFN));
    idx = top = scc = 0; 
    tot = 0;
}
void tarjan(int u){
    int v;
    Low[u] = DFN[u] = ++idx;
    stk[top ++] = u;
    instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next){
        v = edge[i].to;
        if(!DFN[v]){
            tarjan(v);
            if(Low[u] > Low[v])
                Low[u] = Low[v];
        }else if(instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u]){
        scc ++;
        do{
            v = stk[-- top];
            instack[v] = false;
            belong[v] = scc;
        }while(v != u);
    }
}
void solve(int N){
    for(int i = 1; i <= N; i ++){
        if(!DFN[i]){
            tarjan(i);
        }
    }
}
int main(){
    int n, m;
    while(cin>>n>>m, n || m){
        init();
        while(m --){
            int u, v;
            cin>>u>>v;
            add_edge(u, v);
        }
        solve(n);
        if(scc == 1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

