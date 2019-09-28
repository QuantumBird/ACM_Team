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

int q;
typedef pair<int,int> pa;
vector<pa>G[105];
int tmp,sum,tmpa,tmpb;
int flag[105];

int Prim(){
    priority_queue<pa,vector<pa>,greater<pa> >que;
    for(int i=1;i<=tmpb;i++) 
    que.push(make_pair(0,1));//从节点1开始
    int ans = 0;
    int sum = 0;
    while(!que.empty()){
        pa tmp = que.top();
        que.pop();
        if(flag[tmp.second]) continue;
        flag[tmp.second] = 1;
        ans += tmp.first;
        int len = G[tmp.second].size();
        for(int i=0;i<len;++i){
            if(!flag[G[tmp.second][i].second]){
                que.push(make_pair(G[tmp.second][i].first,G[tmp.second][i].second));
            } 
        }
    }
    return ans;
}

void init(){
    for(int i=0;i<103;++i) G[i].clear();
    memset(flag,0,sizeof(flag));
}

int main(){
    while(cin >> q ){
        init();
        sum = q;
        for(int j=1;j<=sum;++j){
            for(int i=1;i<=sum;++i){
                cin >> tmp;
                if(i==j) continue;
                G[j].push_back(make_pair(tmp,i));
                G[i].push_back(make_pair(tmp,j));
            }
        }
        cin >> q;
        while(q--){
            cin >> tmpa >> tmpb;
            G[tmpa].push_back(make_pair(0,tmpb));
            G[tmpb].push_back(make_pair(0,tmpa));
        }
        cout << Prim() << endl;
    }
    return 0;
}