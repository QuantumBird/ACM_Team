#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 20000000;
char ch[maxn];
bool mark[maxn];                              
int mapHash[256];                               
int main() {
    int n, nc;
    while (cin >> n >> nc >> ch) {
        int k = 0;
        int len = strlen(ch);                  
        for (int i = 0; i < len; i++) {
            if (mapHash[ch[i]] == 0) {
                mapHash[ch[i]] = k++;          
            }
        }
        int ans = 0;                          
        for (int i = 0; i <= len - n; i++) {
            int sum = 0;
            for (int j = i; j < i + n; j++) {
                sum = sum * nc + mapHash[ch[j]];
            }
            if (!mark[sum]) {                   
                ans++;
                mark[sum] = true;                
            }
        }
        cout << ans << endl;
    }
    return 0;
}