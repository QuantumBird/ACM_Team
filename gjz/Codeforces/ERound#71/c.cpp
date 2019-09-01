#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 1;
typedef long long ll;
ll note[maxn];
int main(){
    int T;
    cin>>T;
    while(T --){
        int n, a, b;
        string s;
        cin>>n>>a>>b>>s;
        int np, sp;
        np = sp = 0;
        int cnt;
        while(sp < n){
            int tmp = sp;
            cnt = 0;
            while(s[tmp] == s[sp]){
                sp ++;
                cnt ++;
            }
            note[np ++] = cnt;
        }
        ll ans = 0;
//////////////////////////proc array ////////////////////////
        int type = 0;
        for(int i = 0; i < np; i ++){
            int ntype = ((i == 0 || i & 1)? 0: 1);
            if(ntype == 1){
                ans += (a + 2*b)*note[i];
                if(type == ntype){
                    ans += a;
                }else{
                    type = 1;
                }
            }else{
                int ta = (a + b)*note[i] + 2*a + b;
                int tb = (a + 2*b)*note[i];
                if(type == 0){
                    ans += (a + b)*note[i];
                }else if(ta > tb){
                    ans += tb;
                }else{
                    ans += ta - a;
                    type = 0;
                }
            }
        }
        ans += (type == 0? b: 2*b);
/////////////////////////////////////////////////////////////
        cout<<ans<<endl;
    }
    return 0;
}
