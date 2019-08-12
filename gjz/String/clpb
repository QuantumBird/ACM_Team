#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 1;
int tire[maxn][10];
int nptr;
void init(){
    nptr = 1;
    memset(tire, 0, sizeof(tire));
}
bool insert(string & s){
    int p = 1;
    bool ans = false;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i];
        if(tire[p][ch] == 0){
            ans = true;
            tire[p][ch] = ++ nptr;
        }
        p = tire[p][ch];
    }
    return ans;
}
vector<string> vs;
int main(){
    string s;
    int t, n;
    cin>>t;
    while(t--){
        vs.clear();
        init();
        cin>>n;
        bool ans = true;
        for(int i = 0; i < n; i ++){
            cin>>s;
            vs.push_back(s);
        }
        sort(vs.begin(), vs.end());
        for(int i = vs.size() - 1; i >= 0; i --){
//            cout<<vs[i]<<endl; // just for test
            if(insert(vs[i]) == false){
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

