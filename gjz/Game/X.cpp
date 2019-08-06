#include <bits/stdc++.h>
#define N 20000005
 
int a[N], b[N];			// a 为数列， b 保存 a[0...i] 能构造出的最大的数
 
int main()
{
    int n, k;
    int loop = 0, casei = 1;
	scanf("%d",&loop);
	while(loop --){
        scanf("%d%d",&n,&k);
        a[0] = b[0] = 1;
        int i = 0, j = 0;
 
        while(n > a[i]){			// 构建数列
            i ++;
            a[i] = b[i - 1] + 1;
            while(a[j + 1] * k < a[i])
                j ++;
            if(k * a[j] < a[i])
                b[i] = b[j] + a[i];
            else
				b[i] = a[i];
        }
 
        printf("Case %d: ", casei ++);
        if(n == a[i])
			printf("lose\n");
        else{
            int ans;
            while(n){
                if(n >= a[i]){
                    n -= a[i];
                    ans = a[i];
                }
                i --;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
