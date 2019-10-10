#include<bits/stdc++.h>
using namespace std;

int m,n,tmp,q,flag,ans;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        flag = 0,ans = 0;
        vector<int> vec;
        cin >> m >> n;
        for(int i=1;i<=m;++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for_each(vec.rbegin(),vec.rend(),[=](int temp){
            if(temp-flag <= 0 && !ans){
                cout << flag/n << endl;
                ans = 1;
            }else{
                flag += n;
            }
        });
        if(!ans) cout << vec.size() << " ";
    }
    return 0;
}