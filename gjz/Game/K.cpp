#include <iostream>
using namespace std;
#define PYR1 1
#define PYR2 2
int main(){
    int t, n;
    cin>>t;
    int inp, sum;
    while(t--){
        cin>>n;
        sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            cin>>inp;
            sum ^= inp;
            if(inp > 1) cnt ++;
        }
        if(sum){
            if(cnt > 0){
                cout<<PYR1<<endl;
            }else{
                cout<<PYR2<<endl;
            }
        }else{
            if(cnt > 0){
                cout<<PYR2<<endl;
            }else{
                cout<<PYR1<<endl;
            }
        }
    }
    return 0;
}
