#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn = 2e5 + 1;
ull note[maxn];
ull nptr;
int main(){
    int T;
    cin>>T;
    while(T --){
        ull n, a, b;
        ull ans = 0;
        string s;
        nptr = 0;
        memset(note, 0, sizeof(note));
        cin>>n>>a>>b;
        cin>>s;
        int sptr = 0;
        int cnt = 0;
        while(sptr < n){
            int tmp = sptr;
            cnt = 0;
            while(s[tmp] == sptr){
                cnt ++;
                sptr ++;
            }
            note[nptr ++] = cnt;
        }
        note[nptr ++] = cnt;
        cout<<"stastic\n";
        for(int i = 0; i < nptr; i ++){
            if(i & 1){
                ans += (a + 2*b)*note[i];
            }else{
                ans += min((a + 2*b)*note[i], (a + b)*note[i] + 2*a);
            }
        }
        ans -= 2*a;
        cout<<ans<<endl;
    }
    return 0;
}