#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int n;
const int SIZE = maxn*50 + 1;
namespace Tire{
    int nptr = 1;
    struct node{
        int tot;
        int nxt[4];
        node(){
            tot = 0;
            memset(nxt, 0, sizeof(nxt));
        }
    } tire[SIZE];
    inline int idx(char c){
        switch(c){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
    void insert(char *s){
        int p = 1;
        for(int i = 0; i < strlen(s); i ++){
            int ch = idx(s[i]);
            if(tire[p].nxt[ch] == 0)
                tire[p].nxt[ch] == ++ nptr;
            p = tire[p].nxt[ch];
            tire[p].tot ++;
        }
    }
    int query(int nde, int dep){
        if(nde == 0) return 0;
        int ans = dep * tire[nde].tot;
        for(int i = 0; i < 4; i ++){
            ans = max(ans, query(tire[nde].nxt[i], dep + 1));
        }
        return ans;
    }
}
char s[maxn];
int main(){
    int T;
    cin>>T;
    for(int i = 1; i <= T; i ++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%s", s);
            Tire::insert(s);
        }
        int ans = Tire::query(1, 1);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}