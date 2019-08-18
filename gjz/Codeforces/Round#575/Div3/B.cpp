#include <bits/stdc++.h>
using namespace std;
bool a[200010];
int main() {
    int t;
    cin>>t;
    while(t --) {
        int cnt = 0;
        int n, k;
        cin>>n>>k;
        for(int i = 1; i <= n; i ++) {
            int inp;
            cin>>inp;
            if(inp & 1) {
                a[i] = true;
                cnt ++;
            }
        }
        if(cnt%2 == k%2 && cnt >= k) {
            cout<<"YES"<<endl;
            k --;
            for(int i = 1; i <= n && k > 0; i ++) {
                if(a[i]) { 
                    cout<<i<<" ";
                    k --;
                }
            }
            cout<<n<<endl;
        }else
            cout<<"NO"<<endl;
    }
    return 0;
}


