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

const int maxn = 1e5+10;
int q,tmpa,tmpb;
typedef pair<int,int> pa;
int low[maxn];
pa book[maxn];
map<pa,int>mp;
int cep[maxn];
bool tmp(pa a,pa b){
    if(b.second != a.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int lowbit(int i){
    return i&-i;
}

void add(int i){
    while(i < maxn){
        low[i]+=1;
        i+=lowbit(i);
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += low[i];
        i-=lowbit(i);
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> q && q){
        mp.clear();
        memset(low,0,sizeof(low));
        memset(book,0,sizeof(book));
        memset(cep,0,sizeof(cep));
        for(int i=0;i<q;++i){
            cin >> book[i].first >> book[i].second;
            mp[book[i]] = i;
        }
        sort(book,book+q,tmp);
        for(int i=0;i<q;++i){
            add(book[i].first+1);
            cep[mp[book[i]]] = sum(book[i].first);
        }
        for(int i=0;i<q;++i){
            cout << cep[i] << endl;
        }
    }
    return 0;
}