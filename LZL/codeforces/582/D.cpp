#include<bits/stdc++.h>
using namespace std;

int m,n,tmp,MAX,ans = 0x3f3f3f3f;
const int maxn = 2e5+10;
vector<vector<int>> G(maxn);
void judge(int &i){
    int number = 0;
    while(i){
        G[i].push_back(number++);
        i/=2;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0;i<m;++i){
        cin >> tmp;
        MAX = max(MAX,tmp);
        judge(tmp);
    }
    for(int i=0;i<=MAX;++i){
        if(G[i].size() >= n){
            sort(G[i].begin(),G[i].end());
            ans = min(ans,accumulate(G[i].begin(),G[i].begin()+n,0));
        }
    }
    cout << ans << endl;
}