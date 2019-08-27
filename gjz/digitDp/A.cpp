#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 105;
int n,m;
int dp[maxn][maxn];
int maze[maxn][maxn];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
 
bool judge(int x,int y)   //判断是否越界
{
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}
 
int dfs(int i,int j)     
{
    if(dp[i][j])         //如果已经搜索过，直接返回该值就行了
        return dp[i][j];
    int ret = 1;
    for(int k = 0; k < 4; k++)
    {
        int xx = i + dir[k][0];
        int yy = j + dir[k][1];
        if(judge(xx,yy) && maze[i][j] > maze[xx][yy])  //同时要保证比旁边的数大才能继续搜索
            ret = max(dfs(xx,yy)+1, ret);   
    }
    dp[i][j] = ret;    //如果没法搜索说明这个点就是最低点
    return ret;
}
 
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(maze,0,sizeof(maze));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &maze[i][j]);
        int ans = 0;
        for(int i = 1;  i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans = max(dfs(i,j), ans);
        printf("%d\n", ans);
    }
    return 0;
}
