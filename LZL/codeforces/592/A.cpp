#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k,q,flag;
int main(){
    cin >> q;
    while(q--){
        flag = 0;
        cin >> a >> b >> c >> d >> k;
        for(int i=0;i<=k;++i){
            if(c*i>=a && d*(k-i)>=b){
                cout << i << " " << k-i << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}