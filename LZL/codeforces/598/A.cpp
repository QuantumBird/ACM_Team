#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll q;
ll a,b,n,s;

int main(){
    cin >> q;
    while(q--){
        cin >> a >> b >> n >> s;
        s-=(min(a,s/n))*n;
        if(b>=s) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}