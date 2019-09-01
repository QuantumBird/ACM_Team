#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn];
int main(){
    int n;
    while(cin>>n, n){
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i ++){
            int m, n;
            cin>>m>>n;
            a[m] ++;
            a[n + 1] --;
        }
        for(int i = 1; i <= n; i ++){
            a[i] += a[i - 1];
            if(i == 1)
                cout<<a[i];
            else
                cout<<" "<<a[i];
        }
        cout<<endl;
    }
    return 0;
}

