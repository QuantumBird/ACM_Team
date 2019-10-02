#include<bits/stdc++.h>
using namespace std;

int q,m,n,l,r;
char ch;
set<int>se[26];
int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i=0;i<len;++i){
        se[str[i]-'a'].insert(i+1);
    }
    cin >> q;
    while(q--){
        cin >> m;
        if(m==1){
            cin >> n >> ch;
            se[str[n-1]-'a'].erase(n);
            str[n-1] = ch;
            se[ch-'a'].insert(n);
        }else{
            int ans = 0;
            cin >> l >> r;
            for(int i=0;i<26;++i){
                for(int j=l;j<=r;++j){
                    if(se[i].find(j)!=se[i].end()){
                        ++ans;
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}