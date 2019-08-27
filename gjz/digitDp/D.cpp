#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 101;
const ll MOD = 1e9 + 7;
int a[maxn];
ll dp[maxn][10][2];
ll dfs(int pos, int pre, int state, bool leadz, bool limit){
    if(pos < 0){
        if(leadz) return 0;
        return 1;
    }
    if(!limit && dp[pos][pre][state] != -1)
        return dp[pos][pre][state];
    ll ans = 0;
    int top = limit? a[pos]: 9;
    for(int i = 0; i <= top; i ++){
        if(state == 1 && i < pre)
            continue;
        int nste = (state == 1 || (i > pre) && (!leadz))? 1: 0;
        int nldz = ((i == 0) && leadz)? true: false;;
        int nlmt = (limit && (i == a[pos]))? true: false;
        ans += (dfs(pos - 1, i, nste, nldz, nlmt)) % MOD;
    }
    if(!limit && !leadz)
        dp[pos][pre][state] = ans;
    return ans;
}
ll solve(ll x){
    int pos = 0;
    while(x){
        a[pos ++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, 0, 0, true, true);
}
int main(){
    int T;
    cin>>T;
    while(T --){
        memset(dp, -1, sizeof(dp));
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}

