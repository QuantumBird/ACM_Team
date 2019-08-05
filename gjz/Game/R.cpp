#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n, n){
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int inp;
            cin>>inp;
            ans ^= inp;
        }
        cout<<ans<<endl;
    }
    return 0;
}