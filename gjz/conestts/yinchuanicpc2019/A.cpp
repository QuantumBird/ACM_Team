#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
int n, p, q, m;
ll ans;
stack<ll> s;
unsigned int SA, SB, SC;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for(int i = 1; i <= n; i++){
        if(rng61() % (p + q) < p){
            int x=rng61() % m + 1;
            if(!s.size()) s.push(x);
            else if(x>s.top()) s.push(x);
            else s.push(s.top());
        }
        else{
            if(s.size()) s.pop();
            else continue;
        }
        if(s.size()) ans^=i*s.top();
    }
}

int main(void){
    int t,tt=0,i;
    scanf("%d",&t);
    while(t--){
        while(s.size()) s.pop();
        ans = 0;
        gen();
        printf("Case #%d: %lld\n",++tt,ans);
    }
    return 0;
}