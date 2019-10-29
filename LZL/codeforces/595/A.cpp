#include<bits/stdc++.h>

using namespace std;

int m,n;
int book[200];
int dd[200];
int q;
int main(){
    cin >> q;
    int ans = 0;
    while(q--){
        cin >> m;
        int flag = 0;
        for(int i=0;i<m;++i){
            cin >> book[i];
        }
        sort(book,book+m);
        int ans = book[0];
        for(int i=1;i<m;++i){
            if(book[i] - ans ==1){
                flag = 1;
            }
            ans = book[i];
        }
        if(flag) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
}