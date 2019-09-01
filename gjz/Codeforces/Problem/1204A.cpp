#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt = 0;
    for(int i = 0; i < s.length(); i ++)
        if(s[i] == '1')
            cnt ++;
    int ans = (s.length() - 1) / 2 + (cnt > 1? 1: 0);
    cout<<ans<<endl;
    return 0;
}

