#include<bits/stdc++.h>
using namespace std;
//这个方法及其巧妙　差一点想到　可惜并没有
vector<int> G[300000+5];
map<vector<int>,int>mp;
int m,n;
int tmpa,tmpb;
int ans,flag;
vector<int> vec;

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&tmpa,&tmpb);
        G[tmpa].push_back(tmpb);
        G[tmpb].push_back(tmpa);
    }
    for(int i=1;i<=m;++i){
        if(G[i].size()==0){
            cout << -1 << endl;
            return 0;
        }
        sort(G[i].begin(),G[i].end());//保证有序　从而更想一个集合
        if(mp.find(G[i])==mp.end()){ //把vector当做集合
            mp[G[i]] = ++ans;
        }
        if(ans>3){
            cout << -1 << endl;
            return 0;
        }
    }
    if(ans!=3){
        cout << -1 << endl;
        return 0;
    }
    for(int i=1;i<=m;++i){
        if(i==1) cout << mp[G[i]];
        else cout << " " << mp[G[i]];
    }
    putchar('\n');
    return 0;
}