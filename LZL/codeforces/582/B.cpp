#include<bits/stdc++.h>
using namespace std;

int m,n,q,tmp,ans;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        stack<int> sta;
        ans = 0;
        cin >> m;
        for(int i=0;i<m;++i){
            cin >> tmp;
            if(sta.empty()){
                sta.push(tmp);
                continue;
            }
            if(tmp >= sta.top()){
                sta.push(tmp);
                continue;
            }
            while(!sta.empty() && tmp < sta.top()){
                ++ans;
                sta.pop();
            }
            sta.push(tmp);
        }
        cout << ans << endl;
    }
    return 0;
}