#include<bits/stdc++.h>
using namespace std;

int q,m;
string str;

int main(){
    cin >> q;
    while(q--){
        int zero = 0,one = 0;
        cin >> m >>str;
        std::size_t len = str.length();
        for(auto x : str){
            if(x == '0'){
                ++zero;
            }
        }
        one = len - zero;
        if((str[0] =='0' || str[len-1] == '0') && zero == 1){
            cout << len + one + 1 << endl;
        }else{
            cout << len + one << endl;
        }
    }
    return 0;
}