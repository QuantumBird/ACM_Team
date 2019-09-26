#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
int far[maxn],rel[maxn];
int n,k;
int flag;
int t,a,b;
int find(int x)
{
	if(x==far[x])
		return far[x];
	int tt=find(far[x]);
	rel[x]=(rel[far[x]]+rel[x])%2;
	far[x]=tt;
	return far[x];
}
void merge(int x,int y)
{
	int a=find(x);
	int b=find(y);
	if(a==b)
	{
		if(rel[x]==rel[y])
			flag=1;
		return ;
	}
	far[a]=b;
	rel[a]=(rel[x]-rel[y]+1+2)%2;
}
int main()
{
	int Case=1;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		flag=0;
		for(int i=0;i<=n;i++)
		{
			far[i]=i;
			rel[i]=0;
		}
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			if(flag)
				continue;
			merge(a,b);
		}
		printf("Scenario #%d:\n",Case++);
		if(flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
}

