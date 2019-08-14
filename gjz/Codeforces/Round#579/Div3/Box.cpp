#include <iostream>
using namespace std;
const int maxn = 150000 + 1;
bool note[maxn];
int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++){
        int inp;
        cin>>inp;
        if(note[inp] == true){
            if((inp + 1) < maxn && note[inp + 1] == false){
                note[inp + 1] = true;
            }
            if((inp - 1) >= 0 && note[inp - 1] == false){
                note[inp - 1] = true;
            }
        }else{
            note[inp] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i < maxn; i ++)
        if(note[i])
            ans ++;
    cout<<ans<<endl;
    return 0;
}