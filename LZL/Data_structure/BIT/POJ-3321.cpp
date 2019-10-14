//这道题给我一个思路　就是dfs记录时间戳 可以把一棵树存在数组中
//然后把每一棵子树当做一个区间　很巧妙　　
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
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 1e5+10;
vector<vector<int> >G(maxn);
int m,n,tmpa,tmpb,tmp,q;
char ch[10];
int Begin[maxn],End[maxn];
int dis[maxn],apple[maxn];
int Time;

inline int lowbit(int i){
    return i&-i;
}

void add(int i,int w){
    while(i<=n){
        dis[i] += w;
        i += lowbit(i);
    }
}

int sum(int i){
    int ans = 0;
    while(i>0){
        ans += dis[i];
        i -= lowbit(i);
    }
    return ans;
}

void dfs(int now){
    ++Time;
    Begin[now] = Time;
    std::size_t len = G[now].size();
    for(int i=0;i<len;++i){
        dfs(G[now][i]);
    }
    End[now] = Time;
}

int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n-1;++i){
        scanf("%d %d",&tmpa,&tmpb);
        G[tmpa].push_back(tmpb);
    }
    dfs(1);
    for(int i=1;i<=n;++i){
        add(i,1);
        apple[i] = 1;
    }
    scanf("%d",&q);
    getchar();
    for(int i=1;i<=q;++i){
        scanf("%s %d",&ch,&tmp);
        getchar();
        if(ch[0] == 'Q'){
            printf("%d\n",sum(End[tmp]) - sum(Begin[tmp]-1));
        }else{
            if(apple[tmp] == 1){
                add(Begin[tmp],-1);
                apple[tmp] = -1;
            }else{
                add(Begin[tmp],1);
                apple[tmp] = 1;
            }
        }
    }
}