#include <iostream>
#include <cstring>
using namespace std;
const int maxn=10;
const int mod=1e9+7;
long long dp[105][3][15];
long long a[105];
long long dfs(long long pos,int inc,int pre,int lead,int state){
    if(pos<0)   return !lead;
    if(!state && dp[pos][inc][pre]!=-1)
        return dp[pos][inc][pre];
    int top = state? a[pos]: 9;
    long long ans = 0;
    for(int i=0;i<=top;i++){
        if(lead){
            if(i==0)
                ans=(ans+dfs(pos-1,2,0,1,state&&i==top))%mod;
            else
                ans=(ans+dfs(pos-1,2,i,0,state&&i==top))%mod;
        }
        else{
            if(i<pre){
                if(inc!=1)
                    ans=(ans+dfs(pos-1,0,i,0,state&&i==top))%mod;
            }else if(i>pre){
                ans=(ans+dfs(pos-1,1,i,0,state&&i==top))%mod;
            }else 
                ans=(ans+dfs(pos-1,inc,i,0,state&&i==top))%mod;
        }
    }
    if(!state&&!lead)
        dp[pos][inc][pre]=ans;
    return ans;
}
 
int main(){
    long long n,m;
    int T;
    int kase=1;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        long long ans;
        long long cnt=0;
        n=s.length();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            a[n-1-i]=s[i]-'0';
        ans=dfs(n-1,0,0,1,1);
        cout<<ans<<endl;
    }
    return 0;
}
