#include<bits/stdc++.h>
using namespace std;

int m,n,ans;
int one,zero;

int main(){
    cin >> m;
    for(int i=0;i<m;++i){
        cin >> n;
        if(n%2) ++one;
        else ++zero;
    }
    cout << min(one,zero) << endl;
    return 0;
}