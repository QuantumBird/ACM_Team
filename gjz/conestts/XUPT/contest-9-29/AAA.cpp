#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;
ll a[maxn], ans[maxn], n, T;
int main(){
    cin>>T;
    while(T --){
        cin>>n;
        a[1] = 0;
        for(int i = 2; i <= n; i ++){
            cin>>a[i];
            a[i] += a[i - 1];
        }
        ll l, r, tmp;
        l = 2; r = n - 1; ans[1] = 0; ans[2] = tmp = a[n];
        for(int k = 3; k <= n; k ++){
            if(k % 2 == 0){
                tmp += a[r] - a[l];
                r --; l ++;
            }
            ans[k] = ans[k - 1] + tmp;
        }
        for(int i = 1; i <= n; i ++){
            if(i == 1)
                cout<<ans[i];
            else
                cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}

        

