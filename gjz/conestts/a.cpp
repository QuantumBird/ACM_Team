#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin>>T;
    ll a, b;
    while(T --){
        cin>>a>>b;
        ll ans = a & b;
        ans = ans == 0? 1: ans;
        cout<<ans<<endl;
    }
    return 0;
}