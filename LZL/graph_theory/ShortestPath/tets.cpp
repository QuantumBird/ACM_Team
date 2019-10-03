//62MS	444K
#include<stdio.h>
#include<string.h>
#define M 10007
#define inf 0x3f3f3f
int map[M][M],dist[M][2],count[M][2],head[M];
bool vis[M][2];
int n,m,num;
struct E
{
    int v,w,to;
} edg[M<<4];
void addedge(int u,int v,int w)
{
    edg[num].v=v;
    edg[num].w=w;
    edg[num].to=head[u];
    head[u]=num++;
}
void dijkstra(int s)
{
    int pos,min,k;
    for(int i=1; i<=n; i++)
    {
        dist[i][0]=inf;
        dist[i][1]=inf;
    }
    memset(vis,false,sizeof(vis));
    count[s][0]=1;
    dist[s][0]=0;
    for(int i=1; i<2*n; i++)//每个点要用两次
    {
        pos=-1;
        min=inf;
        for(int j=1; j<=n; j++)
            if(!vis[j][0]&&min>dist[j][0])//找最短路,每个节点先更新最短，然后次短
            {
                k=0;
                min=dist[j][0];
                pos=j;
            }
            else if(!vis[j][1]&&min>dist[j][1])//找次短路
            {
                k=1;
                min=dist[j][1];
                pos=j;
            }
        if(pos==-1)break;//如果找不到最短或者次短就结束
        vis[pos][k]=1;
        for(int j=head[pos]; j!=-1; j=edg[j].to)
        {
            int v=edg[j].v;
            int len=dist[pos][k]+edg[j].w;
            if(len<dist[v][0])//如果新路径比最短路要短
            {
                dist[v][1]=dist[v][0];//更新最短路径的长度
                count[v][1]=count[v][0];//更新最短路径的条数
                dist[v][0]=len;//更新次短路径的长度
                count[v][0]=count[pos][k];//更新次短路径的条数
            }
            else if(len==dist[v][0])//如果新路径等于最短路径的长度
                count[v][0]+=count[pos][k];//更新最短路径的条数
            else if(len<dist[v][1])//如果新路径比最短路长且比次短路短
            {
                dist[v][1]=len;//更新次短路的长度
                count[v][1]=count[pos][k];//更新次短路径的条数
            }
            else if(len==dist[v][1])//如果新路径长度等于次短路径的长度
                count[v][1]+=count[pos][k];//更新次短路径的条数
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        int a,b,c,s,t;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);//因为题目中可能有重变，所以要用临街表存储
            addedge(a,b,c);
        }
        scanf("%d%d",&s,&t);
        dijkstra(s);
        int ans=count[t][0];
        if(dist[t][1]==dist[t][0]+1)//如果次短路比最短路长度多1
            ans+=count[t][1];//加上次短路的条数
        printf("%d\n",ans);
    }
}