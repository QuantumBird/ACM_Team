#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
int m,n;
int aa[110],bb[110];
int main(){
    std::ios::sync_with_stdio(false);
    cin >> m;
    for(int i=0;i<m;++i){
        cin >> aa[i];
        mp[aa[i]]++;
    }
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> bb[i];
        mp[bb[i]]++;
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(mp.find(aa[i]+bb[j])==mp.end()){
                cout << aa[i] << " " << bb[j] << endl;
                return 0;
            }
        }
    }
}   