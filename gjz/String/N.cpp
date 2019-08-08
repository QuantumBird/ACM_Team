#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000001;
int nextv[maxn];
char s[maxn];
void get_next(void){
    int i, j;
    nextv[0] = j = -1;
    i = 0;
    while(i < strlen(s)){
        while(j != -1 && s[j] != s[i])
            j = nextv[j];
        nextv[++i] = ++j; 
    }
}
int main(){
    while(~scanf("%s", s), s[0] != '.'){
        get_next();
        int len = strlen(s);
        int length = len - nextv[len];
        if(len % length == 0)
            printf("%d\n", len / length);
        else
            printf("1\n");
    }
    return 0;
}
