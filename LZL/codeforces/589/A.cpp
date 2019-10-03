#include<bits/stdc++.h>
using namespace std;

int l,r;

int check(int tmp){
    map<int,int> mp;
    int tmpa = -1;
    int tmpb = -1;
    while(tmp){
        tmpa = tmp%10;
        tmp/=10;
        if(mp.find(tmpa)!=mp.end()) return 0;
        mp[tmpa] = 1;
    }  
    return 1;
}
int main()
{
    cin >> l >> r;
    for(int i=l;i<=r;++i){
        if(check(i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}