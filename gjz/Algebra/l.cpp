#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 105;
int deg[maxn];
struct Mat{
    ll m[maxn][maxn];
    ll * operator[](int i){
        return m[i];
    }
};
int n, m;
ll det(Mat & a, int n){
    ll ret = 1;
    for(int i = 1; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            while(a[j][i]){
                ll t = a[i][i] / a[j][i];
                for(int k = i; k < n; k ++)
                    a[i][k] = (a[i][k] - a[j][k] * t);
                for(int k = i; k < n; k ++)
                    swap(a[i][k], a[j][k]);
                ret = -ret;
            }
        }
        if(a[i][i] == 0)
            return 0;
        ret = ret*a[i][i];
    }
    return (ret > 0? ret: -ret);
}
 
ll get_ans(){
    int u, v;
    Mat g;
    memset(deg, 0, sizeof deg );
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            g[i][j] = 0;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        u--,v--;
        g[u][v] = g[v][u] = -1;
        deg[u]++;
        deg[v]++;
    }
    for(int i=0; i<n; ++i){
        g[i][i] = deg[i];
    }
    return det(g, n);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<get_ans()<<endl;
    }
    return 0;
}
