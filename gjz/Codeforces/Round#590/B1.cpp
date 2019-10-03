#include <bits/stdc++.h>
using namespace std;
const int maxe = 1e9 + 1;
class Link{
public:
    bool exist[maxe];
    queue<int> que;
    int mlen;
    Link(int maxlen){
        memset(exist, false, sizeof(exist));
        mlen = maxlen;
    }
    void insert(int id){
        if(exist[id] == false){
            que.push(id);
            if(que.size() > mlen){
                exist[que.front()] = false;
                que.pop();
            }
            exist[id] = true;
        }
    }
};
ostream & operator<<(ostream & out, Link & lnk){
    stack<int> stk;
    while(!lnk.que.empty()){
        stk.push(lnk.que.front());
        lnk.que.pop();
    }
    while(!stk.empty()){
        out<<stk.top()<<" ";
        stk.pop();
    }
    return out;
}
int main(){
    int n, k;
    cin>>n>>k;
    Link lnk(k);
    for(int i = 0; i < n; i ++){
        int tmp;
        cin>>tmp;
        lnk.insert(tmp);
    }
    cout<<lnk.que.size()<<endl;
    cout<<lnk<<endl;
    return 0;
}
