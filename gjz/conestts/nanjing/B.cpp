#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll p, ll m){
    ll ans = 1;
    while(p){
        if(p & 1)
            ans =(ans*a)%m;
        a = (a*a)%m;
        p /= 2;
    }
    return ans;
}
ll get_ans(ll a, ll b, ll m){
    if(b == 0) return 1;
    ll ite = a;
    for(int i = 1; i < b; i ++){
        ite = qpow(ite, a, m);
    }
    //cout<<ite<<endl;
    return (ite + 1)%m;
}
int main(){
    int a, b, m, T;
    cin>>T;
    while(T --){
        cin>>a>>b>>m;
        cout<<get_ans(a, b, m)<<endl;
    }
    return 0;
}



