#include<bits/stdc++.h>
using namespace std;
int m,n,q;
int book[120];
int sum;

int main(){
    cin >> q;
    while(q--)
    {
        sum = 0;
        cin >> m;
        for(int i=0;i<m;++i){
            cin >> book[i];
            sum+=book[i];
        }
        if(sum%m==0) cout << sum/m << endl;
        else cout << sum/m+1 << endl;
    }
    return 0;
}