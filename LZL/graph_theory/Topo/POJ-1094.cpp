/*解决问题
１．拓扑排序到第几步会出现环
２．拓扑排序到第几部出现完整序列（有问题）
比如以下样例　其实应该出现环　这很好改　
3 3
A<B
B<C
Sorted sequence determined after 2 relations: ABC.
C>A*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 30;
int n,m;
char top[MAXN];
int in[MAXN],temp[MAXN],mp[MAXN][MAXN];
bool vis[MAXN];
queue<char>que;
//阐述大小关系　与字典序无关　不使用优先队列
int topsort()
{
    memcpy(temp,in,sizeof(in));
    int flag = 1; int k = 0; int cep = 0;
    for(int i=0;i<n;++i){
        cep = 0;
        for(int j=0;j<n;++j){
            if(temp[j]==0){ //存在入度为零就说明未排好序　也有可能点还没出现
                k = j;
                ++cep;
            }
        }
        if(cep == 0) return 0; //优先级高与其他两项
        if(cep > 1) flag = -1;
        for(int j=0;j<n;++j){
            if(mp[k][j]){//参数很重要
                --temp[j]; //减少度为零的点的出边
            }
        }
        que.push(k+65);
        temp[k] = -1;
    }
    return flag;
}
 
int main()
{
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        memset(vis,false,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(mp,0,sizeof(mp));
        memset(top,0,sizeof(top));
        char a,b,c;
        int t=0;
        bool flag=false;
        for(int i=0; i<m; ++i){
            while(!que.empty()) que.pop();
            cin >> a >> c >> b;
            if(flag) continue;
            mp[int(a)-'A'][int(b)-'A']=1;
            ++in[int(b)-'A'];
            t=topsort();
            if(t==0){
                cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
                flag=true;
            }
            else if(t==1){
                cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
                while(!que.empty()){
                    cout << que.front();
                    que.pop();
                }
                cout <<"."<<endl;
                flag=true;
            }
        }
        if(!flag) cout<<"Sorted sequence cannot be determined."<<endl;
    }
    return 0;
}