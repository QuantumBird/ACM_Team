#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
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
        }else{
            k = nxt[k];
        }
    }
}
int get_dictmin(char *s, int len){
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len){
        int t = s[(i + k) % len] - s[(j + k) % len];
        if(t == 0)
            k ++;
        else{
            if(t > 0)
                i += k + 1;
            else
                j += k + 1;
            if(i == j) 
                j ++;
            k = 0;
        }
    }
    return min(i, j);
}
int get_dictmax(char *s, int len){
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len){
        int t = s[(i + k) % len] - s[(j + k) % len];
        if(t == 0)
            k ++;
        else{
            if(t > 0)
                j += k + 1;
            else
                i += k + 1;
            if(i == j) 
                j ++;
            k = 0;
        }
    }
    return min(i, j);
}
char s[maxn];
int main(){
    //ios::sync_with_stdio(false);
    //while(cin>>s){
    while(~scanf("%s", s)){
        int len = strlen(s);
        get_next(s, len);
        int dicmin = get_dictmin(s, len) + 1;
        int dicmax = get_dictmax(s, len) + 1;
        int lp = len - nxt[len];
        int times = len % lp == 0? len / lp: 1;
       // cout<<dicmin<<" "<<times<<" "<<dicmax<<" "<<times<<endl;
        printf("%d %d %d %d\n", dicmin, times, dicmax, times);
    }
    return 0;
}
