#include<bits/stdc++.h>
using namespace std;
//思路对　爆空间了　基本就是强行模拟　题解样例都试了　没问题
vector<int> G[300000+5];
unordered_set<int> se[300000+5];
map<int,int>mp;
int p[300000+5];
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
        for(int j=1;j<=m;++j) se[i].insert(j);
        for(auto x : G[i]){
            se[i].erase(x);
        }
        if(mp.find(i)==mp.end()){
            mp[i] = i;
            for(auto x : se[i]) mp[x] = i; //每一个集合所对应的的set
            vec.push_back(i);
        }else if(se[i]!=se[mp[i]]){//集合已经存在 但不相等
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto x : vec){
        ++flag;
        for(auto d : se[x]){
            p[d] = flag;
        }
    }
    if(vec.size()!=3){
        cout << -1 << endl;
        return 0;
    }
    for(int i=1;i<=m;++i){
        if(i==1) printf("%d",p[i]);
        else printf(" %d",p[i]);
    }
    return 0;
}