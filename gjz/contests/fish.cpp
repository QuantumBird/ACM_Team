#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;
int nt;
int arr[maxn];
ll n, K;
int main(){
    int T;
    //cin>>T;
    scanf("%d", &T);
    while(T --){
        //cin>>n>>K;
        scanf("%lld%lld", &n, &K);
        ll large_sum, small_sum;
        ll can_catch = 0;
        nt = 0;
        large_sum = small_sum = 0;
        for(int i = 0; i < n; i ++){
            ll inp;
            //cin>>inp;
            scanf("%lld", &inp);
            if(inp >= K){
                large_sum += inp;
                can_catch += inp / K;
            }else{
                small_sum += inp;
                arr[nt ++] = inp;
            }
        }
        ll ans = 0;
        if(can_catch >= n - 1){
            ans = K + large_sum + small_sum;
        }else{
            ll diff = n - 1 - can_catch;
            ans = K + large_sum;
            sort(arr, arr + nt);
            while(diff --){
                ans += K;
                small_sum -= arr[-- nt];
            }
            ans += small_sum;
        }
        //cout<<ans<<endl;
        printf("%lld\n", ans);
    }
    return 0;
}