#include <bits/stdc++.h>
using namespace std;
const int maxn = 201*5;
int a[maxn];
int main() {
    int q;
    cin>>q;
    while(q --){
        int n;
        cin>>n;
        for(int i = 0; i < n; i ++){
            int inp;
            cin>>inp;
            a[i] = a[i + n] = a[i + 2*n] = inp;
        }
        bool ans = false;
        for(int i = 0; i < 3*n; i ++){
            int cnt = 1;
            int ptr = i + 1;
            while(a[ptr] > a[ptr - 1] && ptr < 3*n){
                cnt ++;
                ptr ++;
            }
            if(cnt >= n){
                ans = true;
                break;
            }
            cnt = 1;
            ptr = i + 1;
            while(a[ptr] < a[ptr - 1] && ptr < 3*n){
                cnt ++;
                ptr ++;
            }
            if(cnt >= n){
                ans = true;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
