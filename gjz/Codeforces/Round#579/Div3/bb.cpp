#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101*4;
int a[maxn];
bool note[maxn]
int main(){
    int q;
    cin>>q;
    while(q --){
        int n;
        cin>>n;
        n *= 4;
        for(int i = 0; i < n; i ++){
            cin>>a[i];
        }
        sort(a, a + n);
        int s = a[0]*a[n - 1];
        bool ans = true;
        for(int i = 1; i < n - 1; i ++){
            if(i > (n - i - 1)){
                if(s != a[i]*a[n - i - 1]){
                    ans = false;
                    break;
                }
            }
        }
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}