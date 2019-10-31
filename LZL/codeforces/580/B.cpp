#include<bits/stdc++.h>
using namespace std;

int m,n;
int odd;
int even,zero;
long long ans;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> m;
    for(int i=0;i<m;++i){
        cin >> n;
        if(n < 0){
            ++odd;
            ans += -(n+1);
        }else if(n > 0){
            ++even;
            ans += n-1;
        }else{
            ans+=1;
            ++zero;
        }
    }
    if(odd&1){
        if(!zero){
            ans+=2;
        }
    }
    cout << ans << endl;
}