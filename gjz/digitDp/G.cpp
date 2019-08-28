#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 20;
ll dp[maxn][10];
int a[maxn];
ll dfs(int pos, int pre, bool limit){
    if(pos < 0) return 1;
    if(! limit && dp[pos][pre] != -1 && pre >= 0)
        return dp[pos][pre];
    ll ans = 0;
    int top = limit? a[pos]: 9;
    for(int i = 0; i <= top; i ++){
        if(abs(i - pre) < 2)
            continue;
        ans += dfs(pos - 1, ((i == 0 && pre == -1)? pre: i), limit && i == a[i]);
    }
    if(pre >= 0 && !limit)
        dp[pos][pre] = ans;
    return ans;
}
ll solve(ll x){
    memset(dp, -1, sizeof(dp));
    int pos = 0;
    while(x){
        a[++ pos] = x % 10;
        x /= 10;
    }
    return dfs(pos, -1, true);
}
int main(){
    ll a, b;
    cin>>a>>b;
    cout<<(solve(b) - solve(a - 1))<<endl;
    return 0;
}

