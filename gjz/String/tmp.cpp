#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int n;
char s[53];
const int SIZE=maxn*50;
int sz;
struct TrieNode{
    int pre,ed;
    int nxt[4];
}trie[SIZE];
void init(){
    sz=1;
    memset(trie,0,sizeof(trie));
}
inline int idx(const char& c){
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='G') return 2;
    if(c=='T') return 3;
}
void insert(const string& s){
    int p = 1;
    for(int i = 0; i < s.size(); i ++){
        int ch = idx(s[i]);
        if(!trie[p].nxt[ch]) trie[p].nxt[ch] = ++sz;
        p = trie[p].nxt[ch];
        trie[p].pre++;
    }
}

int ans;
void dfs(int d,int now){
    if(!now) return;
    ans = max(ans, d * trie[now].pre);
    for(int i = 0; i < 4; i++) 
        dfs(d+1, trie[now].nxt[i]);
}
int main(){
    int T;
    cin>>T;
    for(int kase = 1; kase <= T; kase ++){
        scanf("%d",&n);
        init();
        for(int i = 1; i <= n; i ++){
            scanf("%s", s);
            insert(s);
        }
        ans = 0;
        dfs(0, 1);
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}