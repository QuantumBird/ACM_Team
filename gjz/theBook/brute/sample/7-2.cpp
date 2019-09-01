#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100;
int a[maxn];
typedef long long ll;
int main(){
    int n, kase = 0;
    while(cin>>n){
        for(int i = 0; i < n; i ++)
            cin>>a[i];
        ll ans = 0;
        for(int s = 0; s < n; s ++){
            ll tmp = a[s];
            ans = max(ans, tmp);
            for(int i = s + 1; i < n; i ++){
                tmp = tmp * a[i];
                ans = max(ans, tmp);
            }
        }
        //if(kase)
        //    printf("\n");
        printf("Case #%d: The maximum product is %lld.\n\n", ++kase, ans);
    }
    return 0;
}

