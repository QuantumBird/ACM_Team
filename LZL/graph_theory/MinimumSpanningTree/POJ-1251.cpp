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
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 105;
int m,n,weight;
char ch,tmp;
int pre[maxn];
int mp[maxn][maxn];
int sum;
struct edge{
    int w;
    char from,to;
    edge(char f,char t,int w):from(f),to(t),w(w){}
    friend bool operator<(edge a,edge b){
        return a.w<b.w;
    }
};

struct Kruskal{
    edge edges[maxn];
    int find(int i){
        return i==pre[i]?i:find(pre[i]);
    }
    void add(char f,char t,int w){
        edges[sum++] = edge(f,t,w);
    }
    void kruskal(){

    }
};

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m;
    Kruskal __temp;
    while(m--){
        cin >> ch >> n;
        while(n--){
            cin >> tmp >> weight;
            temp.add(ch,tmp,weight);
        }
    }
}