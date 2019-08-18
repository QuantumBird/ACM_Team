#include <stdio.h>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define size 5005
#define min(a, b) a > b ? b : a
int num[size << 2], x[size];
void pushup(int rt){
    num[rt] = num[rt << 1] + num[rt << 1 | 1];
}
void build(int l, int r, int rt){
    num[rt] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
 
int qurey(int L, int R, int l, int r, int rt){
    if( L <= l && r <= R)
        return num[rt];
    int m = (l + r) >> 1;
    int ans = 0;
    if(L <= m) ans+=qurey(L, R, lson);
    if(R > m) ans+=qurey(L, R, rson);
    return ans;
}
void updata(int p, int l, int r, int rt){
    if( l == r){
        num[rt]++;
        return;
    }
    int m = ( l + r) >> 1;
    if( p <= m) updata(p, lson);
    else updata(p, rson);
    pushup(rt);
}
int main(){
    int n;
    while(~scanf("%d", &n)){
        int sum = 0;
        build(0, n - 1, 1);
        for( int i= 1; i <= n; i++){
            scanf("%d", &x[i]);
            sum += qurey(x[i], n - 1, 0, n - 1, 1);
            updata(x[i], 0, n - 1, 1);
 
        }
        int tmp = sum;
        for( int i = 1; i <= n; i++){
            sum += n - x[i] - x[i] - 1;
            tmp = min(tmp, sum);
        }
         printf("%d\n",tmp);
    }
    return 0;
}
