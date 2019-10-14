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

int low[32000+10];
int level[32000+10];

int m,n,tmpa,tmpb,tep;

int lowbit(int i){
    return i&(-i);
}

void add(int i){
    while(i<32009){
        low[i]+=1;
        i+=lowbit(i);
    }
}

int sum(int i){
    int ans = 0;
    while(i>0){
        ans+=low[i];
        i-=lowbit(i);
    }
    return ans;
}

int main(){
    while(~scanf("%d",&m)){
        n = m;
        memset(level,0,sizeof(level));
        memset(low,0,sizeof(low));
        while(m--){
            scanf("%d %d",&tmpa,&tmpb);
            level[sum(++tmpa)]++;    //自增的原因是xy范围从零开始
            add(tmpa);
        }
        for(int i=0;i<n;i++) printf("%d\n",level[i]);
    }
    return 0;
}