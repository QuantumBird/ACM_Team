#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
const int maxn = 1e5 + 10;
int tire[maxn][26];
bool endw[maxn];
int tot = 1;
int ans = 0;
void join(string & s){
    int p = 1;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - 'a';
        if(!tire[p][ch])
            tire[p][ch] = ++tot;
        p = tire[p][ch];
    }
    if(endw[p] == false){
        ans ++;
        endw[p] = true;
    }
}
int main(){
    string line;
    while(true){
        getline(cin, line);
        if(line == "#") break;
        ans = 0;
        memset(tire, 0, sizeof(tire));
        memset(endw, false, sizeof(endw));
        stringstream ss(line);
        string word;
        while(ss>>word){
            join(word);
        }
        cout<<ans<<endl;
    }
    return 0;
}