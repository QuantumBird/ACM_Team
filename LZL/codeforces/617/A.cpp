#include <bits/stdc++.h>
using namespace std;

int sum;
int q,Count,T;

int main(){
    cin >> q;
    while(q--){
        Count = 0;
        cin >> sum;
        for(size_t i = 0; i < sum; i++){
            cin >> T;
            if(T&1) ++Count;
        }
        if((!(sum&1) && sum == Count) || !Count){
            cout << "NO\n";
        }else cout << "YES\n";
    }
    return 0;
}