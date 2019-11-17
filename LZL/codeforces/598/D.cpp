#include<bits/stdc++.h>
using namespace std;

int q,m,n;
char str[1000000+10];
using pa = pair<int,int>;
vector<pa>vec;
bool book[1000000+10];

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        int ans = 0;
        cin >> m >> n;
        cin >> str;
        memset(book,0,sizeof(book));
        for(int i=1;i<=m;++i){
            if(str[i]=='0'){
                ++ans;
                vec.emplace_back(make_pair(i,i-ans));
            }
        }
        size_t len = vec.size();
        int flag = 0;
        for(int i=0;i<len;++i){
            if(n-vec[i].second<0) flag = 1;
            if(!flag){
                n-=vec[i].second;
                book[i+1] = true;
            }else{
                book[vec[i].first] = true;
            }
        }
        for(int i=1;i<=m;++i){
            if(book[i]) cout << "0";
            else cout << "1";
        } cout << endl;
    }
}