#include<map>
#include<set>
#include<cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
const int MAXN = 210000;
using namespace std;
int dpa[MAXN][17],dpb[MAXN][17];
int a[MAXN];
int n,m,x,y;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) dpa[i][0] = dpb[i][0] = a[i];

    int len = log2(n);
    for(int i = 1; i <= len; i ++){
        for(int j = 1; j + (1<<i) - 1 <= n; j++){
                dpa[j][i] = max(dpa[j][i-1], dpa[j + (1<<(i-1))][i - 1]);
                dpb[j][i] = min(dpb[j][i-1], dpb[j + (1<<(i-1))][i - 1]);
        }    
    }
    for(int i = 1; i <= m; i ++){
        scanf("%d%d", &x, &y);
        int len = y - x + 1; int l = log2(len);
        int s1 = max(dpa[x][l], dpa[y - (1<<l) + 1][l]);
        int s2 = min(dpb[x][l], dpb[y - (1<<l) + 1][l]);
        printf("%d\n", s1 - s2);
    }
    return 0;
}
