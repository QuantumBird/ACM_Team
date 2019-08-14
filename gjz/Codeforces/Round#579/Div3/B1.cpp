#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1000];
int main() {
    int q;
    cin>>q;
    while(q --){
        int n;
        cin>>n;
        for(int i = 0; i < 4*n; i ++){
            cin>>a[i];
        }
        sort(a, a + 4*n);
        int s = a[0]*a[4*n - 1];
        bool ans = true;
        for(int i = 1; i <= 2*n; i ++) {
            if(i*2 < 4*n){
                if(s != a[i]*a[4*n - i - 1]){
                    //cout<<a[i]*a[4*n - i - 1]<<endl;
                    ans = false;
                    break;
                }
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}