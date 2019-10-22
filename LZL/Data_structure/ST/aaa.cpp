#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
using namespace std;
 
const int maxn= 50005;
struct node
{
    int left,right;
    int val,lazy;
}tree[maxn*4];
int cnt;
int st[maxn],ed[maxn];
int vis[maxn];
vector<int> vec[maxn];
void dfs(int u)
{
    ++cnt;
    vis[u]=1;
    st[u]=cnt;
    for(int i=0;i<vec[u].size();i++)
        dfs(vec[u][i]);
    ed[u]=cnt;
}
void build(int i,int left,int right)
{
    tree[i].left=left;
    tree[i].right=right;
    tree[i].val=-1;
    tree[i].lazy=0;
    if(left==right)
        return;
    int mid=(left+right)>>1;
    build(i<<1,left,mid);
    build(i<<1|1,mid+1,right);
}
void push(int i)
{
    tree[i<<1].lazy=tree[i<<1|1].lazy=1;
    tree[i<<1].val=tree[i<<1|1].val=tree[i].val;
    tree[i].lazy=0;
}
void update(int i,int left,int right,int w)
{
    if(tree[i].left==left&&tree[i].right==right)
    {
        tree[i].lazy=1;
        tree[i].val=w;
        return ;
    }
    if(tree[i].lazy)
    {
        push(i);
    }
    int mid=(tree[i].left+tree[i].right)>>1;
    if(right<=mid)
    {
        update(i<<1,left,right,w);
    }
    else if(left>mid)
    {
        update(i<<1|1,left,right,w);
    }
    else
    {
        update(i<<1,left,mid,w);
        update(i<<1|1,mid+1,right,w);
    }
}
int ans=0;
void query(int i,int aim)
{
    if(tree[i].left==tree[i].right&&tree[i].left==aim)
    {
        ans=tree[i].val;
        return ;
    }
    if(tree[i].lazy)
    {
        push(i);
    }
    int mid=(tree[i].left+tree[i].right)>>1;
    if(aim<=mid)
        query(i<<1,aim);
    else
        query(i<<1|1,aim);
}
int main()
{
    int n,t;
    scanf("%d",&t);
    for(int ic=1;ic<=t;ic++)
    {
        scanf("%d",&n);
        cnt=0;
        int u,v;
        memset(vis,0,sizeof(vis));
        memset(st,0,sizeof(st));
        memset(ed,0,sizeof(ed));
        for(int i=1;i<=n;i++)
            vec[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&v,&u);
            vec[u].push_back(v);
            vis[v]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                break;
            }
        }
        build(1,1,cnt);
        char s[5];
        int m;
        printf("Case #%d:\n",ic);
        scanf("%d",&m);
        while(m--)
        {
            int id,w;
            scanf("%s",s);
            if(s[0]=='C')
            {
                scanf("%d",&id);
                ans=-1;
                query(1,st[id]);
                printf("%d\n",ans);
            }
            else
            {
                scanf("%d%d",&id,&w);
                update(1,st[id],ed[id],w);
            }
        }
    }
    return 0;
}
