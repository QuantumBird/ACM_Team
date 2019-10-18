#include<bits/stdc++.h>
using namespace std;

int m,n,q;

int main(){
    std::ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int zero = 0;
    int one = 0;
    for(auto x : str){
        if(x == '0') ++zero;
        else ++one;
    }
    int len = str.length() - 1;
    if(!len){
        cout << 0 << endl;
        return 0;
    }
    int T = len/2;
    if(zero != len) ++T;
    cout << T << endl;
    return 0;
}