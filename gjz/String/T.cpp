#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 1;
int node[maxn][11];
int nptr = 1;
bool insert(string & s){
    int p = 1;
    int ans = false;
    for(int i = 0; i < s.length(); i++){
        int ch = s[i] - '0';
        if(node[p][10] == 1) return false;
        if(node[p][ch] == 0){
            node[p][ch] = ++nptr;
            ans = true;
        }
        p = node[p][ch];
    }
    node[p][10] = 1;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        bool ans = false;
        nptr = 1;
        memset(node, 0, sizeof(node));
        for(int i = 0; i < n; i ++){
            cin>>s;
            ans = insert(s);
        }
        cout<<(ans? "YES": "NO")<<endl;
    }
    return 0;
}