#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
bool kind(ll n){
    n -= 3;
    if(n < 0) return false;
    return n % 4 == 0;
} 
bool check(ll n){
    if(n < 0) return false;
    if(n % 4 == 0 && n > 0) return false;
    for(ll i = 2; i < n; i ++){
        if(n == 1) break;
        if(n % i == 0){
            if(kind(i)) return false;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T --){
        ll n;
        cin>>n;
        if(check(n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

