#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 20000005;
int len[maxn];
int manacher(string & s){
    string t = "@#";
    int mx = 0, id = 0;
    for(int i = 0; i < s.length(); i ++){
        t += s[i];
        t += '#';
    }
    int ans = 0;
    for(int i = 1; i < t.length(); i ++){
        len[i] = mx > i? min(len[id*2 - i], mx - i): 1;
        while(t[i + len[i]] == t[i - len[i]]) len[i] ++;
        if(i + len[i] > id + len[id]){
            id = i;
            mx = i + len[i];
            ans = max(ans, len[i]);
        }
    }
    return (ans - 1);
}
int main(){
    string s;
    while(cin>>s){
        if(s == "") continue;
        cout<<manacher(s)<<endl;
    }
    return 0;
}