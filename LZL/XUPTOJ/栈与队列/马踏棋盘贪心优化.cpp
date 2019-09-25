#include<bits/stdc++.h>
using namespace std;

namespace{
	struct node{
		int x,y,time;
	};
	const int maxn = 8;
	int x[10] = {0,-2,-1,1,2,2,1,-1,-2};
	int y[10] = {0,1,2,2,1,-1,-2,-2,-1};
	int mp[10][10];
	int vis[10][10];
	stack<node>sta;
	int m,n,flag,steps;
}

namespace Solve{
void show(){
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            mp[i][j]<10?cout << " " <<mp[i][j] : cout << mp[i][j];
            cout << " ";
        }
        putchar('\n');
    }
}
void solve(int a,int b){
    memset(vis,0,sizeof(vis));
    memset(mp,0,sizeof(mp));
    mp[a][b] = 1;
    vis[a][b] = 1;
    steps = 0;
    node now,next;
    now.x = a,now.y = b;
    now.time = 1;
    next.time = 1;
    while(steps<64){
        flag = 0;
        for(int i=now.time;i<=maxn;++i){
            next.x = now.x+x[i];
            next.y = now.y+y[i];
            int xx = next.x;
            int yy = next.y;
            if(now.time<=8 && xx>=1 && xx<=maxn && yy>=1 && yy<=maxn && vis[xx][yy]==0){
                now.time = i+1;
                sta.push(now);
                vis[now.x][now.y] = 1;
                mp[now.x][now.y] = ++steps;
                now = next;
                flag = 1;
                if(steps == 63) mp[xx][yy] = ++steps;
                break;
            }
        }
        if(!sta.empty() && !flag){
            now = sta.top();
            sta.pop();
            vis[now.x][now.y] = 0;
            mp[now.x][now.y] = 0;
            --steps;
        }
    }
    return;
}
}
int main(){
	using namespace Solve;
	cin >> m >> n;
	solve(m,n);
	show();
	return 0;
}