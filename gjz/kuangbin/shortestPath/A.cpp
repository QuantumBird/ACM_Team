#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1001;
int n, t;
int g[maxn][maxn];
void input(){
    cin>>t>>n;
    for(int i = 0; i < t; i ++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = c;
        g[b][a] = c;
    }
}
void Floyd(){
    for(int a = 1; a <= n; a ++)
        for(int b = 1; b <= n; b ++)
            for(int k = 1; k <= n; k ++)
                if(g[a][b] && g[a][k] && g[k][b] &&\
                        (g[a][b] > g[a][k] + g[k][b]))
                    g[a][b] = g[a][k] + g[k][b];
}
int main(){
    input();
    Floyd();
    cout<<g[1][n]<<endl;
    return 0;
}

