#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
priority_queue<long long> pq;
int main(){
    int T, n;
    ll K;
    scanf("%d", &T);
    while(T --){
        scanf("%d%lld", &n, &K);
        ll sum = K;
        ll num = n - 1;
        while(! pq.empty())
            pq.pop();
        for(int i = 0; i < n; i ++){
            ll inp;
            scanf("%lld", &inp);
            pq.push(inp % K);
            sum += inp;
            num -= inp / K;
        }
        while(num > 0){
            num --;
            sum += K - pq.top();
            pq.pop();
        }
        printf("%lld\n", sum);
    }
    return 0;
}
