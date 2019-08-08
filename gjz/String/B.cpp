#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxm = 1e4 + 5;
const int maxn = 1e6 + 5;
char w[maxm], t[maxn];
ull p = 233;
int main(){
    int tmp;
    cin>>tmp;
    while(tmp --){
        scanf("%s", w);
        scanf("%s", t);
        int lenw = strlen(w);
        int lent = strlen(t);
        if(lenw > lent){
            printf("0\n");
            continue;
        }
        ull k = 1;
        for(int i = 0; i < lenw; i ++)
            k *= p;
        ull wh, th;
        wh = th = 0;
        for(int i = 0; i < lenw; i ++){
            wh = wh*p + w[i] - 'A' + 1;
            th = th*p + t[i] - 'A' + 1;
        }
        int ans = 0;
        for(int i = 0; i + lenw <= lent; i ++){
            if(wh == th)
                ans ++;
            if(i + lenw < lent)
                th = th*p + (t[i + lenw] - 'A' + 1) - (t[i] - 'A' + 1)*k;
        }
        cout<<ans<<endl;
    }
}
