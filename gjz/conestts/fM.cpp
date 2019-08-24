#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 1;
priority_queue<long long,vector<long long>, greater<long long> > pq;
int main(){
    int T, n;
    long long K;
    //ios::sync_with_stdio(false);
    //cin>>T;
    scanf("%lld", &T);
    while(T --){
        //cin>>n>>K;
        scanf("%d%lld", &n, &K);
        long long int lSum = 0;
        long long int mSum = 0;
        long long int lcnt = 0;
        long long int mint = INT_MAX;
        long long int canCatch = 0;
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; i ++){
            long long int inp;
            //cin>>inp;
            scanf("%lld", &inp);
            if(inp >= K){
                lSum += inp;
                lcnt ++;
                canCatch += inp / K;
            }else{
                mSum += inp;
                pq.push(inp);
            }
            mint = min(mint, inp);
        }
        long long int ans = 0;
        if(canCatch >= n - 1){
            ans += K + mSum + lSum;
        }else{
            ans += lSum + K;
            int diff = n - canCatch - 1;
            while(diff --){
                ans += K;
                mSum -= pq.top();
                pq.pop();
            }
            ans += mSum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
