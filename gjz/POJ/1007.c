
#include<stdio.h>
#include<string.h>
 
#define M 200
struct dna
{
	char str[M];
	int ans;
};
struct dna d[M];
struct dna t;
void main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%s",d[i].str);
		d[i].ans=0;
		for(j=0;j<n;j++)
		{
			for(k=j;k<n;k++)
			if(d[i].str[j]>d[i].str[k])
				d[i].ans++;
		}
	}
 
	for(i=0;i<m;i++)
		for(j=i;j<m;j++)
		{
			if(d[i].ans>d[j].ans)
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
		}
 
	for(i=0;i<m;i++)
	{
		printf("%s\n",d[i].str);
	}
	return 0;
}

