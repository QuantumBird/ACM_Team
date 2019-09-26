#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;
int ufs[maxn];
void init(int size){
    for(int i = 0; i < size; i ++)
        ufs[i] = i;
}
int find(int x){
    if(x != ufs[x])
        ufs[x] = find(ufs[x]);
    return ufs[x];
}
bool same(int x, int y){
    x = find(x);
    y = find(y);
    return x == y;
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    ufs[x] = y;
}
int main(){
    int n, m, kase = 0;
    ios::sync_with_stdio(false);
    while(cin>>n>>m, n || m){
        int ans = n;
        init(n + 1);
        while(m --){
            int a, b;
            cin>>a>>b;
            if(!same(a, b)){
                ans --;
                merge(a, b);
            }
        }
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}

