#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n, k;
    cin>>n>>k;
    ll t = n / k;
    if(t & 1)   
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}