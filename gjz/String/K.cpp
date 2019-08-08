#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 500000;
struct node{
    int tot;
    int child[26];
    node(){
        tot = 0;
        memset(child, 0, sizeof(child));
    }
} tire[maxn];
int nptr = 0;
void insert(string & s){
    int p = 0;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - 'a';
        if(tire[p].child[ch] == 0)
            tire[p].child[ch] = ++ nptr;
        p = tire[p].child[ch];
        tire[p].tot ++;
    }
}
int query(string & s){
    int p = 0;
    for(int i = 0; i < s.length(); i ++){
        int ch = s[i] - 'a';
        if(tire[p].child[ch] == 0)
            return 0;
        p = tire[p].child[ch];
    }
    return tire[p].tot;
}
int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s == "") break;
        insert(s);
    }
    while(cin>>s){
        cout<<query(s)<<endl;
    }
    return 0;
}