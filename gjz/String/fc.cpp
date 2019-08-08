#include <stdio.h>
#include <string.h>
const int maxn = 20000005;
char str[maxn];
char tmp[maxn];
int len[maxn];
int ans;
int sl;
void manacher(void){
    len[0] = 1;
    int mx = 0, id = 0;
    int ans = 0;
    for(int i = 0; i < sl; i ++){
        len[i] = mx > i? min(len[2*id - i], mx - i): 1;
        while(t[i + len[i]] == t[i - len[i]]) len[i] ++;
        if(i + len[i] > id + len[id]){
            id = i;
            mx = i + len[i];
            ans = max(ans, len[i]);
        }
    }
}
int main(){
    while(scanf("%s", str)){
        sl = strlen(str);
        for(int i = len ; i >= 0; i --){
    		t[(i << 1) + 1] = '#';
    		t[(i << 1) + 2] = t[i];
    	}
    }
    return 0;
}