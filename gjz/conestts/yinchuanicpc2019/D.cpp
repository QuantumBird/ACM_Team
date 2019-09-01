#include <stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++){
        long long a, b;
        scanf("%lld%lld", &a, &b);
        double ansa = (a == 1)? 1: 0.5;
        double ansb = double(b + 1) / (2.0 * b);
        printf("Case #%d: %.6lf %.6lf\n", i, ansa, ansb);
    }
    return 0;
}
