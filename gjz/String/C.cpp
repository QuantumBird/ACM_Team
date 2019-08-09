#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
int nxt[maxn];
void get_next(char *s, int len){
    nxt[0] = -1;
    int j = 0, k = -1;
    while(j < len){
        if(k == -1 || s[j] == s[k]){
            j ++;
            k ++;
            if(s[j] != s[k])
                nxt[j] = k;
            else
                nxt[j] = nxt[k];
        }else
            k = nxt[k];
    }
}
int main(){
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    char s[maxn];
    while(t--){
        cin>>s;
        int len = strlen(s);
        get_next(s, len);
        int loop_len = len - nxt[len];
        if(len % loop_len  == 0 && nxt[len] != 0)
            cout<<0<<endl;
        else{
            cout<<(loop_len - len % loop_len)<<endl;
        }
    }
    return 0;
}
