#include<bits/stdc++.h>
using namespace std;

int m,n;

int main(){
    cin >> m;
    if(m&1){
        cout << "YES\n";
        for(int i=1;i<=m;++i){
            cout << i << " " << i+m << " ";
        }
    }else{
        cout << "NO\n";
    }
}