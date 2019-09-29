#include<bits/stdc++.h>
using namespace std;
int q,m,n;
char mp[2010][2010];
int vis[2010][2010];
int tmpx_S,tmpy_S;
int tmpx_T,tmpy_T;
int len,tmp;
int x[6] = {-4,4,-2,2,-2,2};
int y[6] = {0,0,-6,-6,6,6};
int c[6] = {-2,2,-1,1,-1,1};
int d[6] = {0,0,-3,-3,3,3};
struct node{
	int x,y,steps;
};
bool check(int t_xx,int t_yy){
 	if((mp[t_xx][t_yy] != '/' && mp[t_xx][t_yy] != '-' && mp[t_xx][t_yy] != '\\'))
 	return true;
 	return false;
}
void bfs(int a,int b){
	queue<node>que; 
	node tmp = {a,b,1}; 
	que.push(tmp);
	vis[a][b] = 1;
	while(!que.empty()){
		node temp = que.front();
		que.pop();
		if(temp.x == tmpx_T && temp.y == tmpy_T){
			printf("%d\n",temp.steps);
			return;
		}
		for(int i=0;i<6;++i){
			int xx = temp.x+x[i];
			int yy = temp.y+y[i];
			int t_xx = temp.x+c[i];
			int t_yy = temp.y+d[i];
			if(check(t_xx,t_yy) && !vis[xx][yy]){
				node tt = {xx,yy,temp.steps+1};
				que.push(tt);
				vis[xx][yy] = 1;
			}
		}
	}
}
int main()
{
	scanf("%d",&q);
	while(q--){
		for (int i=0;i<2010;i++)
		for (int j=0;j<2010;j++)
		vis[i][j]=0;
		scanf("%d %d",&m,&n);
        len = 0;
		getchar();
        tmp = 5+(m-1)*4+2;
		for(int i=0;i<tmp;++i){
			cin.getline(mp[i],2010);
            int t = strlen(mp[i]);
			len = max(len,t);
		}

		for(int k=0;k<tmp;++k){
			for(int q=0;q<len;++q){
				if(mp[k][q]=='T'){
					tmpx_T=k,tmpy_T=q;
				}
				if(mp[k][q]=='S'){
					tmpx_S=k,tmpy_S=q;
				}
			}
		}
		bfs(tmpx_S,tmpy_S);
	}
	return 0;
}