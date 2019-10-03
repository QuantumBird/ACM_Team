//bfs建图 + 最小生成树
//希望熟练掌握邻接表和邻接矩阵写法
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstdio>
#include<cstring>
using namespace std;

namespace{
    const int INF = 0x3f3f3f3f;
    const int maxn = 2000;
    typedef pair<int,int>pa;
    typedef pair<int,pa>pii;
    bool vis[maxn][maxn];
    int w[maxn][maxn];
    char mp[maxn][maxn];
    int low[maxn];
    int q,m,n,flag;
    map<pa,int>id;
    vector<pa>vec;
    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};
}

int bfs(pa& p){//结点的结构体选取很重要
    memset(vis,0,sizeof(vis));
    queue<pii>que;
    que.push(make_pair(0,p));//第一个参数为步数
    vis[p.first][p.second] = true;
    while(!que.empty()){
        pii tmp = que.front();
        que.pop();
        for(int i=0;i<4;++i){
            int xx = tmp.second.first+x[i];
            int yy = tmp.second.second+y[i];
            if(mp[xx][yy]!='#' && xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy]){
                vis[xx][yy] = 1;
                if(mp[xx][yy] == 'A' || mp[xx][yy] == 'S'){
                    w[flag][id[make_pair(xx,yy)]] = tmp.first+1;
                    w[id[make_pair(xx,yy)]][flag] = tmp.first+1;//无向图
                }else{//" "
                    que.push(make_pair(tmp.first+1,make_pair(xx,yy)));
                }
            }
        }
    }
}

int Prim(int cep){//邻接矩阵的表示法
    //low数组维护一个距x点的最短距离
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    vis[0] = true;//从零点开始找
    int ans = 0,p = 0;
    for(int i=0;i<cep;++i) low[i] = w[p][i]; 
    for(int i=1;i<cep;++i){
        int Max = INF;
        for(int j=0;j<cep;++j){//找到最小权
            if(!vis[j] && Max>low[j]){
                Max = low[p=j];
            }
        }
        ans += Max;
        vis[p] = 1;
        for(int j=0;j<cep;++j){
            if(!vis[j] && low[j] > w[p][j])
                low[j] = w[p][j];
        }
    }
    return ans;
}

void init(){
    id.clear();
    vec.clear();
    memset(low,0,sizeof(low));
}

int main(){
    scanf("%d",&q);
    while(q--){
        init();
        scanf("%d %d",&m,&n);
        cin.getline(mp[0],100);
        for(int i=0;i<n;++i){
            cin.getline(mp[i],100);//gets用不了
            for(int j=0;j<m;++j){
                if(mp[i][j]=='A' || mp[i][j]=='S'){
                    id[make_pair(i,j)] = vec.size(); //给每一个点给予一个编号
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        int temp=vec.size();//全是零的原因是因为vec.size()等于零　菜如狗啊
        for(int i=0;i<temp;++i)
        for(int j=0;j<temp;++j)
        if(i==j) w[i][j] = 0;
        else w[i][j] = INF;

        for(int i=0;i<vec.size();++i){
            flag = id[vec[i]];
            bfs(vec[i]);
        }
        printf("%d\n",Prim(vec.size()));
    }
    return 0;
}