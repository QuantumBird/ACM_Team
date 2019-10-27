#include<bits/stdc++.h>
using namespace std;

int m,l,r;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m >> l >> r;
    int ans = m-(l-1);
    int flag = 1;
    for(int i=m-l+2;i<=m;++i){
        ans += flag*=2;
    }
    cout << ans << " ";
    ans = 0;
    flag = 1;
    for(int i=1;i<=r-1;++i){
        ans += pow(2,i-1);
    }
    flag = pow(2,r-1);
    ans += (m-(r-1))*flag;
    cout << ans << endl;
    return 0;
}