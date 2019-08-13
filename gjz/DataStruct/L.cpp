#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1010][1010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int n,m,x,y;
		scanf("%d%d%d%d",&n,&m,&x,&y);
		int ans=0;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&dp[i][j]);
				dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]; 
				if(i>=x&&j>=y)
				ans=max(ans,dp[i][j]-dp[i-x][j]-dp[i][j-y]+dp[i-x][j-y]); 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

