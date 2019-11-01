#include<bits/stdc++.h>
using namespace std;
int book[200000+10];
int cet[200000+10];
map<int,int>mp;
int m,n;
int judge(int i){
    int len = 0;
    while(i){
        i/=10;
        ++len;
    }
    return len;
}
int main(){
    cin >> m >> n;
    int len = judge(n);
    vector<int>vec;
    for(int i=1;i<=len;++i){
        vec.push_back(pow(10,i));
    }
    for(int i=0;i<m;++i){
        cin >> book[i];
        book[i]%=n;
        for(auto x : vec){
            mp[(book[i]*(x%n))%n]++;
        }
    }
    int ans = 0;
    for(int i=0;i<m;++i){
        if((mp.find(n-book[i])) != mp.end()){
            ans += mp[n-book[i]];
            cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}