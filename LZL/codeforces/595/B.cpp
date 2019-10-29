#include<bits/stdc++.h>

using namespace std;

int m,n;
int flag[200000+10];
int book[200000+10];
int q;

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        stack<int> sta;
        unordered_set<int> se;
        memset(flag,0,sizeof(flag));
        cin >> m;
        for(int i=1;i<=m;++i){
            cin >> book[i];
        }
        for(int i=1;i<=m;++i){
            int j = i;
            if(!flag[j]){
                while(se.find(j) == se.end()){
                    se.insert(j);
                    sta.push(j);
                    j = book[j];
                }
                size_t len = sta.size();
                while(sta.size()){
                    flag[sta.top()] = len;
                    sta.pop();
                }
                se.clear();
            }
        }
        for(int i=1;i<=m;++i){
            cout << flag[i] << " ";
        }
        cout << endl;
    }  
    return 0;  
}