//想来怎么做了　数学功底不好　式子列不出来
//可以用树状数组维护一个区间小于x的和　
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<cstdio>
using namespace std;

struct node{
    int D,H;
};
const int  maxn = 100000+10;
int m,tmpa,tmpb,cnt;
node book[maxn];
node dis[maxn];
int num[maxn];
int weight[maxn];

void init(){
    memset(book,0,sizeof(book));
    cnt = 1;
}

bool tmp1(node a,node b){
    return a.D < b.D;
}

bool tmp2(node a,node b){
    return a.H < b.H;
}

int lowbit(int i){
    return i&-i;
}

long long sum(int i){
    long long ans = 0;
    while(i>0){
        ans += num[i];
        i -= lowbit(i);
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> m){
        init();
        for(int i=0;i<m;++i){
            cin >> book[i].D >> book[i].H;
        }
        sort(book,book+m,tmp1);
        dis[0].D = 1;
        for(int i=1;i<m;++i){
            ++cnt;
            if(book[i].D == book[i-1].D){
                dis[i].D = dis[i-1].D;
            }else{
                dis[i].D = cnt;
            }
        }
        sort(book,book+m,tmp2);
        dis[0].H = 1; cnt = 1;
        for(int i=1;i<m;++i){
            ++cnt;
            if(book[i].H == book[i-1].H){
                dis[i].H = dis[i-1].H;
            }else{
                dis[i].H = cnt;
            }
        }
        for(int i=0;i<m;++i){
  
        }
    }
}