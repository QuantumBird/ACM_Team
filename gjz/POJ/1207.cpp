#include <iostream>
using namespace std;
int getlen(int n){
    int ans = 0;
    while(n != 1){
        ans ++;
        n = n & 1? 3*n + 1: n / 2;
    }
    return ans;
}
int main(){
    int i, j;
    while(cin>>i>>j){
        int a = min(i, j);
        int b = max(i, j);
        int ans = 0;
        for(int k = a; k <= b; k ++){
            ans = max(ans, getlen(k));
        }
        cout<<i<<" "<<j<<" "<<(ans + 1)<<endl;
    }
    return 0;
}

