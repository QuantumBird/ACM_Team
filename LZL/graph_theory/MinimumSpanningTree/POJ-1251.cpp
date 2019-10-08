//Kruskal模板
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
int m,n,weight,num;
char ch,tmp;
int pre[maxn];
int sum;
struct edge{
    int w;
    char from,to;
    edge() = default; //很重要　不然无法申请数组　因为有其他构造函数　默认生成的删除
    edge(char f,char t,int w):from(f),to(t),w(w){}
    bool operator<(const edge& a)const{ //不使函数为const可能在某些编译器下无法通过编译
        return w<a.w;
    }
};

struct Kruskal{
    edge edges[maxn];
    void init(){
        for(int i=1;i<=num;++i){
            pre[i] = i;
        }
    }
    int find(int i){
        return i==pre[i]?i:pre[i]=find(pre[i]);
    }
    void add(char f,char t,int w){
        edges[sum++] = edge(f,t,w);
    }
    int kruskal(){
        int ans = 0,cnt = 0;
        sort(edges,edges+sum);
        for(int i=0;i<sum;++i){
            int u = edges[i].from - 64;
            int v = edges[i].to - 64;
            if(find(u) != find(v)){
                ans += edges[i].w;
                pre[find(u)] = find(v);
                if(++cnt >= num-1) return ans;
            }
        }
        return -1;
    }
}KK;

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> m && m){
        sum = 0;
        num = m;
        KK.init();
        m--;
        while(m--){
            cin >> ch >> n;
            while(n--){
                cin >> tmp >> weight;
                KK.add(ch,tmp,weight);
            }
        }
        cout << KK.kruskal() << endl;
    }
    return 0;
}