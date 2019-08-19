#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 111;
int a[maxn], dp[maxn][maxn];
int n;
int main(){
    int t;
    cin>>t;
    int kase = 0;
    while(t --){
        cin>>n;
        for(int i = 1; i <= n; i ++)
            cin>>a[i];
        memset(dp, 0, sizeof(dp));
        for(int i = n; i >= 1; i --){
            for(int j = i; j <= n; j ++){
                dp[i][j] = dp[i + 1][j] + 1;
                for(int k = i + 1; k <= j; k ++){
                    if(a[i] == a[k])
                        dp[i][j] = min(dp[i][j],\
                                dp[i + 1][k] + dp[k + 1][j]);
                }
            }
        }
        cout<<"Case "<<++kase<<": "<<dp[1][n]<<endl;
    }
    return 0;
}

