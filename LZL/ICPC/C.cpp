#include<bits/stdc++.h>
using namespace std;
int q,m,n;
char mp[10005][10005];
int vis[10005][10005];
int tmpx_S,tmpy_S;
int tmpx_T,tmpy_T;
int len,tmp;
int x[6] = {-4,4,-2,2,-2,2};
int y[6] = {0,0,-6,-6,6,6};
int c[6] = {-2,2,-1,1,-1,1};
int d[6] = {0,0,-3,-3,3,3};
const int INF = 0x3f3f3f3f;
struct node{
	int x,y,steps;
};
int bfs(int a,int b){
	queue<node>que; 
	node tmpp = {a,b,1}; 
	que.push(tmpp);
	vis[a][b] = 0;
	while(!que.empty()){
		node temp = que.front();
		que.pop();
		if(temp.x == tmpx_T && temp.y == tmpy_T){
			return temp.steps;
		}
		for(int i=0;i<6;++i){
			int xx = temp.x+x[i];
			int yy = temp.y+y[i];
			int t_xx = temp.x+c[i];
			int t_yy = temp.y+d[i];
            if(t_xx>=0 && t_xx<tmp && t_yy>=0 && t_yy<len && mp[t_xx][t_yy]==' '){
                if(temp.steps+1<vis[xx][yy] && xx>=0 && xx<tmp && yy>=0 && yy<len){
                    node tt = {xx,yy,temp.steps+1};
                    que.push(tt);
                    vis[xx][yy] = temp.steps+1;
                }
            }
		}
	}
    return -1;
}
int main()
{
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&m,&n);
        getchar();
		tmp = 4*m + 3;
/* 		for(int i=0;i<tmp;++i){
			cin.getline(mp[i],2010);
		} */
        len = 6*n + 3;
		for(int k=0;k<tmp;++k){
            gets(mp[i]);
			for(int q=0;mp[k][q]!='\0';++q){
                vis[k][q] = INF;
				if(mp[k][q]=='T'){
					tmpx_T=k,tmpy_T=q;
				}
				if(mp[k][q]=='S'){
					tmpx_S=k,tmpy_S=q;
				}
			}
		}
		printf("%d\n",bfs(tmpx_S,tmpy_S));
	}
	return 0;
}