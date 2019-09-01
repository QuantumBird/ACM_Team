#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 21;
int a[maxn];
int dp[maxn][2];
int dfs(int pos, int pre, int sta, bool limit){
    if(pos == -1) return 1;
    if(!limit && dp[pos][sta] != -1) return dp[pos][sta];
    int up = limit? a[pos]: 9;
    int tmp = 0;
    for(int i = 0; i <= up; i ++){
        if(pre == 6 && i == 2) continue;
        if(i == 4) continue;
        tmp += dfs(pos - 1, i, i == 6, limit && i == a[pos]);
    }
    if(! limit) dp[pos][sta] = tmp;
    return tmp;
}
int solve(int x){
    int pos = 0;
    while(x){
        a[pos ++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 0, true);
}
int main(){
    int l, r;
    while(cin>>l>>r, l + r){
        memset(dp, -1, sizeof(dp));
        cout<<(solve(r) - solve(l - 1))<<endl;
    }
    return 0;
}

