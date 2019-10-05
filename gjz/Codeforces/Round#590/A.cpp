#include <bits/stdc++.h>
using namespace std;
int main(){
    int T, n, inp, tmp;
    cin>>T;
    while(T --){
        cin>>n;
        tmp = 0;
        for(int i = 0; i < n; i ++){
            cin>>inp;
            tmp += inp;
        }
        cout<<(tmp / n + (tmp % n? 1: 0))<<endl;
    }
    return 0;
}
