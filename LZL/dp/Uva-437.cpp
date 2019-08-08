#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
int m;
int x,y,z;
int ans,flag;
typedef struct 
{
    int l,w,h;
}node_t;
node_t book[4000];
int d[4000];

int graph(int a,int b,int c)
{
    book[ans].l=max(a,b);
    book[ans].w=min(a,b);
    book[ans++].h=c;
}

vector<int> vec[4000];

int dp(int j)
{
    if(d[j]>0) return d[j];
    d[j]=book[j].h;
    for(auto x : vec[j])
    {
        d[j] = max(d[j],dp(x)+book[j].h);
    }
    return d[j];
}

int create(int h)
{
    for(int i=1;i<=ans;i++)
    {
        if((book[h].l > book[i].l && book[h].w > book[i].w) || (book[h].l>book[i].w &&book[h].w>book[i].l))
        {
            vec[h].push_back(i);
        }
    }
}

int main()
{
    int number=0;
    while(cin >> m && m)
    {
        memset(d,0,sizeof(d));
        memset(book,0,sizeof(book));
        flag=0;
        ans=1;
        for(int i=0;i<m;i++)
        {
            cin >> x >> y >> z;
            graph(x,y,z);
            graph(z,x,y);
            graph(y,z,x);
        }
        for(int i=1;i<ans;i++)
        {
            vec[i].clear();
            create(i);
        }
        for(int i=1;i<=ans;i++)
        {
            flag=max(flag,dp(i));
        }
        printf("Case %d: maximum height = %d\n",++number,flag);
    }
    return 0;
}