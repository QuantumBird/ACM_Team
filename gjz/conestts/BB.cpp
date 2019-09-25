#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1e4;
int n, v, q;
int dp[maxn];
int ca[1000 + 10];
int main(){
    cin>>q;
    while(q --){
        cin>>n>>v;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i ++)
            cin>>ca[i];
        cout<<0;
        for(int i = 0; i < n - 1; i ++){
            for(int j = v; j >= 0; j --){
                if(j - ca[i] >= 0 && dp[j] < dp[j - ca[i]] + 1)
                    dp[j] = dp[j - ca[i]] + 1;
            }
            /*
            cout<<"DEBUG"<<i + 1<<endl;
            for(int i = 1; i <= v; i ++)
                cout<<dp[i]<<" ";
            cout<<endl;*/
            int ans = max(0, i - dp[v - ca[i + 1]]);
            //cout<<i - dp[v - ca[i]] + 1<<" ";
            cout<<ans<<" "<<endl;
        }
        cout<<endl;
    }
    return 0;
}

