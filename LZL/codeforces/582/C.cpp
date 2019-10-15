#include<bits/stdc++.h>
using namespace std;

long long m,n,q;
int book[15][15];

int main(){
    std::ios::sync_with_stdio(false);
    for(int i=0;i<=9;++i){
        int sum = 0;
        int j = 0;
        for(j=0;j<=9;++j){
            book[i][j] = (i*j)%10;
            sum += book[i][j];
        }
        book[i][10] = sum;
    }
    cin >> q;
    while(q--){
        cin >> m >> n;
        long long ans = 0;
        long long flag = m/n;
        ans += book[n%10][10]*(flag/10);
        flag%=10;
        for(int i=1;i<=flag;++i){
            ans += book[n%10][i];
        }
        cout << ans << endl;
    }
    return 0;
}