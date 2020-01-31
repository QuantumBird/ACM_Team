#include <bits/stdc++.h>
using namespace std;
int n;
long long a,b,c,d;
int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d;
        long long T = max(a,max(b,c));
        long long difference = 3*T-(a+b+c);
        if(d>=difference && (d-difference)%3==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}