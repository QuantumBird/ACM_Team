#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    long long int tmp, inp;
    cin>>tmp;
    t --;
    while(t --){
        cin>>inp;
        if(tmp != 1)
            tmp = __gcd(tmp, inp);
    }
    long long int ans = 0;
    for(long long i = 1; i * i <= tmp; i ++){
        if(tmp % i == 0){
            ans ++;
            if(i * i != tmp)
                ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}