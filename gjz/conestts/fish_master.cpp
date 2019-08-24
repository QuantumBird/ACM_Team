#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;
priority_queue<long long,vector<long long>, greater<long long> > pq;
ll arr[maxn];
int nt;
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        ll n, K;
        scanf("%lld%lld", &n, &K);
        ll sum = 0;
        ll ans = K;
        ll can_catch = 0;
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; i ++){
            ll inp;
            scanf("%lld", &inp);
            sum += inp;
            pq.push(K - inp % K);
            can_catch += inp / K;
        }
        ans += sum;
        if(can_catch < n - 1){
            ll diff = n - 1 - can_catch;
            while(diff --){
                ans += K - pq.top();
                pq.pop();
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
