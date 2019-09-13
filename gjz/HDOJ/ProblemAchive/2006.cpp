#include <cstdio>
int main(){
    int n, ans, t;
    while(~scanf("%d", &n)){
        for(int i = 0, ans = 1; i < n; i ++)
            scanf("%d", &t), (t & 1? ans *= t:1);
        printf("%d\n", ans);
    }
    return 0;
}

