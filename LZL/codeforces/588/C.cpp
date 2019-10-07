#include<bits/stdc++.h>
using namespace std;

int m,n;
bool mp[10][10];
bool vis[10][10];
int tmpa,tmpb;
int color[10];
int flag,ans;

int judge(){ //枚举所有的边数
    int res = 0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=7;++i){
        for(int j=1;j<=7;++j){
            if(mp[i][j]){
                int u = color[i];
                int v = color[j];
                if(!vis[u][v]){
                    ++res;
                    vis[u][v] = vis[v][u] = true;
                }
            }
        }
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);//cin慢的原因是因为为了兼容C
    std::cin.tie(nullptr);//默认绑定cout　调用flush刷新缓冲区　加快执行效率
    cin >> m >> n;
    for(int i=0;i<n;++i){
        cin >> tmpa >> tmpb;
        mp[tmpa][tmpb] = true;
        mp[tmpb][tmpa] = true;
    }
    if(m<=6){
        cout << n << endl;
        return 0;
    }
    for(int i=1;i<=m;++i){
        color[i] = i;
        if(i==7) color[i] = 6;//随便设置　任何一个数都可以连接其他五个 但为了全排列 6最佳
    }
    do{
        ans = max(ans,judge());
    }while(next_permutation(color+1,color+8));//精髓所在 全排列　学到了
    cout << ans << endl;
    return 0;
}