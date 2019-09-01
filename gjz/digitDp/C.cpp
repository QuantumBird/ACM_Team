#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[20][3];
int a[20];
ll dfs(int pos, int state, bool limit){
    if(pos <= 0) return state == 2;
    if(!limit && dp[pos][state] != -1) return dp[pos][state];
    ll ans = 0;
    int up = limit? a[pos]: 9;
    for(int i = 0; i <= up; i ++){
        int tst = state;
        if(state == 0 && i == 4)
            tst = 1;
        else if(state == 1 && i != 4 && i != 9)
            tst = 0;
        else if(state == 1 && i == 9)
            tst = 2;
        ans += dfs(pos - 1, tst, limit && i == up);
    }
    if(! limit)
        dp[pos][state] = ans;
    return ans;
}
ll solve(int x){
    memset(dp, -1, sizeof(dp));
    int pos = 0;
    while(x){
        a[++ pos] = x % 10;
        x /= 10;
    }
    a[pos + 1] = 0;
    return dfs(pos, 0, true);
}
int main(){
    int T;
    cin>>T;
    while(T --){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}

