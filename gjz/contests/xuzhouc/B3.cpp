#include <iostream>
using namespace std;
const int maxn = 1e9 + 1;
bool mark[maxn];
int nxt[maxn];
int n, q;

int find_set(int id){
    while(nxt[id] != id){
        if(nxt[id] == -1) return -1;
        id = nxt[id];
    }
    return (id > n? -1: id);
}

void zipPath(int s, int fal){
    int pre = s;
    s = nxt[s];
    while(s != nxt[s]){
        if(nxt[s] == -1) return;
        nxt[pre] = fal;
        pre = s;
        s = nxt[s];
    }
}

int main(){
    cin>>n>>q;
    for(int i = 0; i <= n; i ++) nxt[i] = i;
    while(q --){
        
    }
}