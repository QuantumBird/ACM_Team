#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <climits>
using namespace std;
map<string, int> note;
const int MAXN = INT_MAX;
int tire[MAXN][4];
int end[MAXN];
int tot = 1;
int order(char c){
    switch(c){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
        case 'T': return 3;
    }
}
void join(char *s){
    int len = strlen(s);
    int p = 1;
    for(int i = 0; i < len; i ++){
        int ch = order(s[i]);
        if(!tire[p][ch])
            tire[p][ch] = ++tot;
        p = tire[p][ch];
    }
    end[p] ++;
}
int main(){

    return 0;
}