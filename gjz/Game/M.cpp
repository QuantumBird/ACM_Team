#include <iostream>
using namespace std;
const int MAXN = 100 + 1;
int heap[MAXN];
int main(){
    int n;
    while(cin>>n, n){
        for(int i = 0; i < n; i ++)
            cin>>heap[i];
        int ans = 0;
        int tmp;
        int note = 0;
        for(int i = 0; i < n; i ++)
            note ^= heap[i];
        for(int i = 0; i < n; i ++){
            tmp = note^heap[i];
            for(int j = 0; j <= heap[i]; j ++){
                if(tmp^j == 0){
                    ans ++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}