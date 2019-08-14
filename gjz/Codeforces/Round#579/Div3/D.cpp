#include <iostream>
using namespace std;
const int maxn = 150000 + 10;
int note[maxn];
int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++){
        int t;
        cin>>t;
        note[t] ++;
    }
    int ans = 0;
    for(int i = 0; i < maxn; i ++){
        if(note[i] > 0){
            ans ++;
            if(note[i] > 2){
                if((i - 1) >= 0 && note[i - 1] == 0){
                    ans ++;
                }
                if((i + 1) < maxn && note[i + 1] == 0){
                    ans ++;
                    note[i + 1] --;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}