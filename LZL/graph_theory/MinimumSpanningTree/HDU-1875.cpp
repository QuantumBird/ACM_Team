#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstdio>
#include<cstring>
using namespace std;

namespace{
    const int maxn = 105;
    int m,n,weight,num,q,Index;
    int tmpa,tmpb;
    int pre[maxn];
    int sum;
    struct edge{
        int from,to;
        double w;
        edge() = default; //很重要　不然无法申请数组　因为有其他构造函数　默认生成的删除
        edge(char f,char t,int w):from(f),to(t),w(w){}
        bool operator<(const edge& a)const{ //不使函数为const可能在某些编译器下无法通过编译
            return w<a.w;
        }
    };
    struct spot{
        int x,y,index;
    };
    struct Kruskal{
        edge Edges[maxn*maxn];
        int find(int i){
            return i==pre[i]?i:pre[i]=find(pre[i]);
        }
        void init(){
            for(int i=0;i<=m;++i){
                pre[i] = i;
            }
        }
        void add(int f,int t,double w){
            Edges[Index++] = edge(f,t,w);
        }
        double kruskal(){
            init();
            double ans = 0;
            int cnt = 0;
            sort(Edges,Edges+Index);
            for(int i=0;i<Index;++i){
                int u = Edges[i].from;
                int v = Edges[i].to;
                if(find(u)!=find(v)){
                    ans += Edges[i].w;
                    pre[find(u)] = find(v);
                    if(++cnt >= m-1) return ans;
                }
            }
            return -1;
        }
    };
}

int main(){
    cin >> q;
    while(q--){
        Kruskal KK;
        vector<spot>vec;
        Index = 0;
        cin >> m;
        for(int i=1;i<=m;++i){
            cin >> tmpa >> tmpb;
            spot temp = {tmpa,tmpb,i};
            vec.emplace_back(std::move(temp));
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                if(i==j) continue;
                double temp = sqrt(abs(pow(vec[i].x-vec[j].x,2))+abs(pow(vec[i].y-vec[j].y,2)));
                if(temp>=10 && temp<=1000){
                    KK.add(i+1,j+1,temp*1000);
                }
            }
        }
        double temp = KK.kruskal();
        if(temp==-1){
            cout << "oh!\n";
        }else{
            printf("%.1f\n",temp/10);
        }
    }
    return 0;
}