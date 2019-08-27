#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll dp[25][3];
int a[25];
ll dfs(int pos, int state, int limit){
    if(pos <= 0)    return state == 2;
    if(!limit && dp[pos][state] != -1)  
        return dp[pos][state];
    ll ans = 0;
    int end = limit? a[pos]: 9;  
    for(int i = 0; i <= end; i++){
        int ts = state;       
        if(state == 0 && i == 4)
            ts = 1;
        else if(state == 1 && i != 4 && i != 9)
            ts = 0;
        else if(state == 1 && i == 9)
            ts = 2;
        ans += dfs(pos - 1, ts, limit && i == end);
    }
    if(!limit)
        dp[pos][state] = ans;
    return ans;
}
 
ll solve(ll x){
    int pos = 0;
    while(x){
        a[++pos] = x % 10;
        x/=10;
    }
    a[pos + 1] = 0;
    return dfs(pos, 0, true);
}
 
int main(){
    int t;
    ll n;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
