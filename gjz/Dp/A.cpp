#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int dp[101][101],sum[101],a[101],n;
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        for(int len = 2 ; len <= n ; len++){
            for(int i = 1 ; i <=n ;i++){
                int j = i+len-1;
                if(j>n) continue;
                for(int k = i ; k < j ;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        int a1 = dp[1][n];

        for(int i = 0 ; i <= n ; i++)
            for(int j = 0 ; j <= n ; j++)
                dp[i][j] = 1e8;
        for(int i = 0 ;i<=n ;i++)
            dp[i][i] = 0;
        for(int len = 2 ; len <= n ; len++){
            for(int i = 1 ; i <=n ;i++){
                int j = i+len-1;
                if(j>n) 
                    continue;
                for(int k = i ; k < j ;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        int a2 = dp[1][n];
        cout<<a2<<" "<<a1<<endl;
    }
    return 0;
}

