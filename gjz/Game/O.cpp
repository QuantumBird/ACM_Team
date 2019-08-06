#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    while(cin>>n>>m){
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int a, b;
            cin>>a>>b;
            ans ^= (abs(a - b) - 1);
        }
        if(ans){
            cout<<"I WIN!\n";
        }else{
            cout<<"BAD LUCK!\n";
        }
    }
    return 0;
}
