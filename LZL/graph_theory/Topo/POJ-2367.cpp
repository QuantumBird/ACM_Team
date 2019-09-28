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
#include<cstdio>
using namespace std;

int m,tmp,n;
int in[110];
vector<int>G[110];
queue<int>q;

int topo(){
    priority_queue<int,vector<int>,greater<int> > que;
    for(int i=1;i<=m;++i){
        if(in[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int temp = que.top();
        que.pop();
        q.push(temp);
        int len = G[temp].size();
        for(int i=0;i<len;++i){
            int x = G[temp][i];
            in[x]--;
            if(in[x]==0)
                que.push(x);
        }
    }
}

int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        while(scanf("%d",&n) && n!=0){
            G[i].push_back(n);
            in[n]++;
        }
    }
    topo();
    int x=1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(x){
            printf("%d",temp);
            x = 0;
        }else printf(" %d",temp);
    }
    return 0;
}