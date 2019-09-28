#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

namespace{
    typedef long long ll;
    ll m,n;
    ll book[100000+10];
    ll Left,Right;
    ll ans,flag;

    bool Check(ll mid){
        ans = 0;
        if(n==1){ //防止n为零　会整除零　抛出错误
            for(int i=1;i<=m;++i){
                if(book[i] > mid){
                    return false;
                }
            }
            return true;
        }
        for(int i=1;i<=m;++i){
            if(book[i]-mid>0){
                ans+=((book[i]-mid)%(n-1)?(book[i]-mid)/(n-1)+1:(book[i]-mid)/(n-1));
            }
        }
        if(ans>mid) return false;
        else return true;
    }
}

int main(){
    scanf("%lld",&m);
    for(int i=1;i<=m;++i){
        scanf("%lld",&book[i]);
    }
    scanf("%lld",&n);
    Left = 1;Right = 1e9;
    while(Left<=Right){
        int mid = Left + ((Right - Left) / 2);
        if(!Check(mid)){
            Left = mid+1;
        }else{
            flag = mid;
            Right = mid-1;
        }
    } 
    cout << flag << endl;
    return 0;
}