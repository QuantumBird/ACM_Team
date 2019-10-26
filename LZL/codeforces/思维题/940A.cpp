#include<bits/stdc++.h>
using namespace std;

int book[110];
int main(){
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;++i){
        cin >> book[i];
    }
    sort(book,book+m);
    int Min = book[0];
    int ans = 0;
    for(int i = m-1;i>=0;--i){
        if(book[i]-Min>n){
            ++ans;
        }else break;
    }
    cout << ans << endl;
    return 0;
}