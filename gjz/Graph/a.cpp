#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int inf = INT_MAX;
int d[110][110];
int x, y, z;
int main(){
    int kase = 1;
    while(cin>>x>>y>>z, x && y && z){
        for(int i = 1; i <= x; i ++)
            for(int j = 1; j <= x; j ++)
                d[i][j] = (i == j? 0: inf);
        while(y --){
            int u, v, w;
            cin>>u>>v>>w;
            if(d[u][v] > w)
                d[u][v] = d[v][u] = w;
        }
        for(int k = 1; k <= x; k ++)
            for(int i = 1; i <= x; i ++)
                for(int j = 1; j <= x; j ++)
                    if(d[i][k] < inf && d[k][j] < inf)
                        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        if(kase != 1)
            cout<<endl;
        cout<<"Case #"<<kase ++<<endl;
        while(z --){
            int n, m;
            cin>>n>>m;
            int ans = d[n][m];
            if(ans < inf)
                cout<<ans<<endl;
            else
                cout<<"no path"<<endl;
        }
    }
    return 0;
}

