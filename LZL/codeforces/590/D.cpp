#include<bits/stdc++.h>
using namespace std;

int book[30];
int sum;
int main(){
    string str;
    cin >> str;
    size_t len = str.length();
    for(int i=0;i<len;++i){
        if(book[str[i]-'0']==0){
            book[str[i]-'0'] = 1;
            ++sum;
        }
    }
    cout << sum << endl;
    return 0;
}