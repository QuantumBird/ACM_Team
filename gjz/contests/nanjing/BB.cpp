#include <iostream>
using namespace std;
typedef long long ll;

ll q_pow(ll a, ll b, ll m){
    ll ans = 1;
    if(b == 0) return 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % m;
        a = (a*a) % m;
        b /= 2;
    }
    return ans % m;
}

ll get_ans(ll a, ll b, ll m){
    if(b == 0) return 1;
    int ite = 0;
    for(int i = 0; i <= b; i ++){
        ite = q_pow(a, ite, m);
        cout<<a<<": "<<ite<<endl;
    }
    return (ite) % m;
}

int main(){
    int a, b, m, t;
    cin>>t;
    while(t --){
        cin>>a>>b>>m;
        cout<<get_ans(a, b, m)<<endl;
    }
    return 0;
}
