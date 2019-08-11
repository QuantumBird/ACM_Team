#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 1;
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
int get_loop(char *s, int len){
    get_next(s, len);
    int lp = len - nxt[len];
    return (len % lp == 0? len / lp: 1);
}
int get_dict(char *s, int len, bool ismax){
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len){
        int t = s[(i + k) % len] - s[(j + k) % len];
        if(t == 0)
            k ++;
        else{
            if(t > 0)
                (ismax? j: i) += k + 1;
            else
                (ismax? i: j) += k + 1;
            if(i == j)
                j ++;
            k = 0;
        }
    }
    return min(i, j) + 1;
}
char s[maxn];
int main(){
    while(~scanf("%s", s)){
        int len = strlen(s);
        int times = get_loop(s, len);
        printf("%d %d %d %d\n",
                get_dict(s, len, false), times,
                get_dict(s, len, true), times);
    }
    return 0;
}

