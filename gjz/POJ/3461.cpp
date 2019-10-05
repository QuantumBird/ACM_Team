#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
char w[maxn], t[maxn];
int nxt[maxn];

void preKMP(char s[], int knxt[]){
    int m = strlen(s);
    int i, j;
    j = knxt[0] = -1;
    i = 0;
    while(i < m){
        while(j != -1 && s[i] != s[j]) j = knxt[j];
        if(s[++ i] == s[++ j]) knxt[i] = knxt[j];
        else knxt[i] = j;
    }
}

int kmp(char T[], char P[], int knxt[]){
    int n = strlen(T);
    int m = strlen(P);
    int i, j, ans = 0;
    preKMP(P, knxt);
    i = j = 0;
    while(i < n){
        while(j != -1 && T[i] != P[j]) j = knxt[j];
        i ++; j ++;
        if(j >= m){
            ans ++;
            j = knxt[j];
        }
    }
    return ans;
}

int main(){
    int kse;
    cin>>kse;
    while(kse --){
        cin>>w>>t;
        memset(nxt, 0, sizeof(nxt));
        cout<<kmp(t, w, nxt)<<endl;
    }
    return 0;
}

