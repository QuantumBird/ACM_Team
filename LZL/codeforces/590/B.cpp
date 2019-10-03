#include<bits/stdc++.h>
using namespace std;
int m,n,tmp;
queue<int> que;
unordered_set<int>se;

int main(){
    cin >> m >> n;
    for(int i=0;i<m;++i){
        cin >> tmp;
        if(se.find(tmp)==se.end()){
            if(que.size()==n){
                se.erase(que.front());
                que.pop();
                que.emplace(tmp);
                se.insert(tmp);
            }else{
                que.emplace(tmp);
                se.insert(tmp);
            }
        }
    }
    stack<int> sta;
    int flag = 0;
    cout << que.size() << endl;
    while(!que.empty()){
        sta.emplace(que.front());
        que.pop();
    }
    while(!sta.empty()){
        if(!flag){
            cout << sta.top();
            flag = 1;
        }else cout << " " << sta.top();
        sta.pop();
    }
    return 0;
}