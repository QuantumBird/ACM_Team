#include <iostream>
using namespace std;
int main(){
    int t, n;
    cin>>t;
    int inp, sum;
    while(t--){
        cin>>n;
        sum = 0;
        bool flag = true;
        for(int i = 0; i < n; i ++){
            cin>>inp;
            sum ^= inp;
            if(inp != 1) flag = false;
        }
        if(flag){
            if(n & 1){
                cout<<"Brother"<<endl;
            }else{
                cout<<"John"<<endl;
            }
        }else{
            if(sum){
                cout<<"John"<<endl;
            }else{
                cout<<"Brother"<<endl;
            }
        }
    }
    return 0;
}
