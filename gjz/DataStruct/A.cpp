#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 1;
int num[maxn];
int main() {
    int n, a, b;
    while(cin>>n, n) {
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i ++) {
            cin>>a>>b;
            num[a] ++;
            num[b + 1] --;
        }
        for(int i = 1; i <= n; i ++) {
            num[i] += num[i - 1];
            if(i == 1)
                cout<<num[i];
            else
                cout<<" "<<num[i];
        }
        cout<<endl;
    }
    return 0;
}

