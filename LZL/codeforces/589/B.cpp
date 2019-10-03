#include<bits/stdc++.h>
using namespace std;
int r,c,p[1005][1005],ans=1;
int main()
{
	memset(p,0,sizeof p);
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		int a;
		cin>>a;
		for(int j=1;j<=a;j++)p[i][j]=1;
		p[i][a+1]=2;
	}
	for(int i=1;i<=c;i++)
	{
		int a;
		cin>>a;
		for(int j=1;j<=a;j++)
		{
			if(p[j][i]==2)ans=0;
			p[j][i]=1;
		}
		if(p[a+1][i]==1)ans=0;
		p[a+1][i]=2;
	}
    int flag=0;
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)if(p[i][j]==0){
        ans=ans*2%1000000007;
    }
	printf("%d\n",ans);
	return 0;
}