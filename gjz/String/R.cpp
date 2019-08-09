#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 300001;
string ss[maxn];
int tire[maxn][26], sn[maxn];
int nptr = 1;
void insert(string & s){
    int p = 1;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - 'a';
        if(tire[p][ch] == 0) tire[p][ch] = ++nptr;
        p = tire[p][ch];
        sn[p] ++;
    }
}
void display(string & s){
    int p = 1;
    for(int i = 0; i < s.length(); i ++){
        if(sn[p] == 1) return;
        int ch = s[i] - 'a';
        cout<<s[i];
        p = tire[p][ch];
    }
}
int main(){
    int tot = -1;
    while(cin>>ss[++tot])
        insert(ss[tot]);
    for(int i = 0; i <= tot; i ++){
        cout<<ss[i]<<" ";
        display(ss[i]);
        cout<<endl;
    }
    return 0;
}