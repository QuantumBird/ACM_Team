#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxm = 3e5 + 10;
const int maxn = 18;
int dpx[maxm][maxn], dpn[maxm][maxn];
int a[maxm];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1; i <= n; i ++) cin>>a[i];
    for(int i = 1; i <= n; i ++) dpx[i][0] = dpn[i][0] = a[i];
    int len = log2(n);
    for(int i = 1; i <= len; i ++) {
        for(int j = 1; j + (1<<i) - 1 <= n; j ++) {
            dpx[j][i] = max(dpx[j][i - 1], dpx[j + 1 << (i - 1)][i - 1]);
            dpn[j][i] = min(dpn[j][i - 1], dpn[j + 1 << (i - 1)][i - 1]);
        }
    }
    while(m --) {
        int a, b;
        cin>>a>>b;
        int t = log2(b - a + 1);
        int x = max(dpx[a][t], dpx[b - 1<<t + 1][t]);
        int y = min(dpn[a][t], dpn[b - 1<<t + 1][t]);
        cout<<(x - y)<<endl;
    }
    return 0;
}

