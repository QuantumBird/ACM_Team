#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 21;
int a[maxn];
ll dp[maxn][10];
ll dfs(int pos, int pre, bool zero, bool limit){
    if(pos <= 0) return 1;
    if(dp[pos][pre] != -1 && !limit && !zero)
        return dp[pos][pre];
    ll ans = 0;
    int top = limit? a[pos]: 9;
    for(int i = 0; i <=top; i ++)
        if(!zero && abs(i - pre) > 1 || zero)
            ans += dfs(pos - 1, i, limit && i == top, zero && i == 0);
    if(!limit && !zero)
        dp[pos][pre] = ans;
    return ans;
}
ll solve(ll x){
    int pos = 1;
    while(x){
        a[pos ++] =  x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, true, true);
}
int main(){
    memset(dp, -1, sizeof(dp));
    ll a, b;
    while(cin>>a>>b){
        cout<<(solve(b) - solve(a - 1))<<endl;
    }
    return 0;
}

