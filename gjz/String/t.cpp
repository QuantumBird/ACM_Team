#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1e5 + 1;
int tire[maxn][10];
int nptr;
void init(){
    memset(tire, 0, sizeof(tire));
    nptr = 1;
}
void insert(string & s){
    int p = 1;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - '0';
        if(tire[p][ch] == 0)
            tire[p][ch] = ++ nptr;
        p = tire[p][ch];
    }
}
bool query(string & s){
    int p = 1;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - '0';
        if(tire[p][ch] == 0)
            return false;
        p = tire[p][ch];
    }
    return true;
}
string str[10000 + 1];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        init();
        for(int i = 0; i < n; i ++){
            cin>>str[i];
            insert(str[i]);
        }
        bool ans = true;
        for(int i = 0; i < n; i ++){
            if(query(str[i])){
                ans = false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

