#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<cstdio>
#include<unordered_map>
using namespace std;

stack<char> sta;
queue<char> que;
vector<char>vec;
unordered_map<char,int>mp;

int solve(){
    for(auto x : vec){
        if(x>=97 && x<=122) que.emplace(x);
        else if(sta.empty()) sta.emplace(x);
        else if(x == '(') sta.emplace(x);
        else if(x == ')'){
            while(1){
                char tmp = sta.top();
                sta.pop();
                if(tmp == '(') break;
                que.emplace(tmp);
            }
        }else if(mp[x]>mp[sta.top()]) sta.emplace(x);
        else {
            while(1){
                if(sta.empty()){
                    break;
                }
                if(mp[x]<=mp[sta.top()]){
                    que.emplace(sta.top());
                    sta.pop();
                }else break;
            }
            sta.emplace(x);
        }
    }
}

int main(){
    mp['*'] = 2;
    mp['/'] = 2;
    mp['+'] = 1;
    mp['-'] = 1;
    string str;
    cin >> str;
    vec.assign(str.begin(),str.end());
    solve();
    if(!sta.empty()){
        que.emplace(sta.top());
        sta.pop();
    }
    while(!que.empty()){
        cout << que.front();
        que.pop();
    }
    putchar('\n');
    return 0;
}
//a+b-a*((c+d)/e-f)+g
//ab+acd+e/f-*-g+8