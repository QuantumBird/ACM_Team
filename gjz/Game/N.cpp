#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100010;
vector<int> v[MAXN];
int get_sg(int u, int pre){
    int ret = 0;
    for(int i = 0; i < v[u].size(); i ++){
        if(v[u][i] != pre){
            ret ^= (1 + get_sg(v[u][i], u));
        }
    }
    return ret;
}
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1; i <= n; i ++){
            v[i].clear();
        }
        for(int i = 1; i < n; i ++){
            int a, b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(get_sg(1, -1)){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}