#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int T,n,k,mod;
LL bit[55];
int main(){
    scanf("%d",&T);
    for (int z=1;z<=T;++z){
        scanf("%d%d%d",&n,&k,&mod);
        printf("Case #%d: ",z);
        if (k>=n)
        {
            LL ans=1;
            for (int i=1;i<=n;++i) ans=ans*i%mod;
            printf("%lld\n",ans);
            continue;
        }
        bit[0]=1;
        for (int i=1;i<=n;++i) bit[i]=1LL*bit[i-1]*(k+1)%mod;
        LL ans=0;
        //sorted
        ans=bit[n-k];
        //left shift
        for (int len=2;len<=n-k;++len) 
            ans+=1LL*(n-k-len+1)*bit[n-k-1]%mod,ans%=mod;
        //right shift
        for (int len=3;len<=n-k;++len) 
        ans+=1LL*(n-k-len+1)*bit[n-k-len+1]%mod,ans%=mod;
        //last k
        for (int i=1;i<=k;++i) ans=ans*i%mod;
            printf("%lld\n",ans);
    }
    return 0;
}
