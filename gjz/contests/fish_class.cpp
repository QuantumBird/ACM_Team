#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
namespace fish{
    template <typename T>
    class solver{
        T n_, K_;
        T sum, num;
        priority_queue<T> pq;
        public:
        solver(T n, T K){
            n_ = n;
            K_ = K;
            sum = K;
            num = n - 1;
        }
        void input(){
            for(int i = 0; i < n_; i ++){
                T inp;
                scanf("%lld", &inp);
                pq.push(inp % K_);
                sum += inp;
                num -= inp / K_;
            }
        }
        T solve(){
            while(num > 0){
                num --;
                sum += K_ - pq.top();
                pq.pop();
            }
            return sum;
        }
    };
}

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        ll n, K;
        scanf("%lld%lld", &n, &K);
        fish::solver<ll> s(n, K);
        s.input();
        printf("%lld\n", s.solve());
    }
    return 0;
}

