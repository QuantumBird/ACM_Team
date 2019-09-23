#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
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

int m,n;
char mp[2010][2010];
int vis[2010][2010];
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
struct node{
    int x,y,dir;
    friend ostream& operator <<(ostream& os,const struct node& tmp){
        os << "(" << tmp.x << "," << tmp.y << "," << tmp.dir << ")";
        return os;
    }
};
int flag;
stack<node> sta,temp;
int dfs(int a,int b){
    if(flag) return 0;
    if(a == m && b == n){
        sta.push({m,n,0});
        flag = 1;
        return 0;
    }
    for(int i=0;i<4;++i){
        int xx = a+x[i];
        int yy = b+y[i];
        if(mp[xx][yy]=='0' && vis[xx][yy]==0 && xx>=1 && xx<=m && yy>=1 && yy<=n){
            sta.push({a,b,i+1});
            vis[xx][yy] = 1;
            if(dfs(xx,yy)){
            vis[xx][yy] = 0;
            sta.pop();
            }else break;
        }
    }
    if(flag) return 0;
    return 1;
}

int main(){
    cin >> m >> n;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin >> mp[i][j];
        }
    }
    dfs(1,1);
    while(!sta.empty()){
        temp.push(sta.top());
        sta.pop();
    }
    while(!temp.empty()){
        node &tmp = temp.top();
        cout << tmp;
        temp.pop();
    }
    return 0;
}