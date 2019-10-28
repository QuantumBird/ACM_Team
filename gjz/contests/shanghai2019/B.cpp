#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 1;
int note[maxn];
int main(){
    int T, m, n, kase = 0;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i ++) note[i] = 0;
        while(m --){
            int a, b;
            scanf("%d%d", &a, &b);
            note[a] ++;
            note[b + 1] --;
        }
        int ans = note[1] & 1;
        for(int i = 2; i <= n; i ++){
            note[i] += note[i - 1];
            if(note[i] & 1) ans ++;
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
