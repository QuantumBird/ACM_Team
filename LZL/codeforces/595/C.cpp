#include<bits/stdc++.h>

using namespace std;

int m,n,q,flag;
int force[15] = {1,3,9,27,81,243,729,2187,6561,19683};

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        cin >> m;
        int ans = 0;
        for(int i=0;i<10;++i){
            if(ans < m){
                ans += force[i];
            }else break;
        }
        for(int i=9;i>=0;--i){
            if(ans - force[i] >= m){
                ans -= force[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}