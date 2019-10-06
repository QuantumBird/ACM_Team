#include<bits/stdc++.h>
using namespace std;

int m,n,flag,ans;
string str;

int main(){
    cin >> m >> n >> str;
    size_t len = str.length();
    if(n==0){
        cout << str << endl;
        return 0;
    }
    if(m==1){
        cout << 0 << endl;
        return 0;
    }
    if(str[0]!='1') --n;
    cout << '1';
    for(int i=1;i<len;++i){
        if(str[i]!='0' && n){
            --n;
            cout << '0';
        }else cout << str[i];
    }
    cout << endl;
    return 0;
}