#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
const int N = 222;
const int INF = INT_MAX;

struct Node{
    int to, cap, rev;
};
 
vector<Node> v[N];
bool used[N];
 
void add_edge(int from,int to,int cap){
    v[from].push_back((Node){to,cap,v[to].size()});
    v[to].push_back((Node){from,0,v[from].size()-1});
}
 
int dfs(int s,int t,int f){
    if(s==t)    return f;
    used[s]=true;
    for(int i=0;i<v[s].size();i++){
        Node &tmp = v[s][i];
        if(used[tmp.to]==false && tmp.cap>0){
            int d=dfs(tmp.to,t,min(f,tmp.cap));
            if(d>0){
                tmp.cap-=d;
                v[tmp.to][tmp.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
 
int max_flow(int s,int t){
    int flow=0;
    for(;;){
        memset(used,false,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0)
            return flow;
        flow+=f;
    }
}
int main(){
    int T;
    cin>>T;
    int n,m, kase = 0;
    while(T --){
        cin>>n>>m;
        memset(v,0,sizeof(v));
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            add_edge(x,y,z);
        }
        cout<<"Case "<<++kase<<": ";
        cout<<max_flow(1,n)<<endl;
    }
}
