#include <bits/stdc++.h>
using namespace std;

int sum,q;

int answer(int T){
    int ans = 0;;
    int lhs = T-(T%10);
    int rhs = T%10;
    while(true){
        ans += lhs;
        rhs += lhs/10;
        lhs = (rhs - rhs%10);
        if(rhs < 10) return ans+rhs;
        rhs = rhs%10;
    }
}

int main(){
    cin >> q;
    while(q--){
        cin >> sum;
        cout << answer(sum) << endl;
    }
    return 0;
}