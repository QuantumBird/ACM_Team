#include <iostream>
#include <algorithm>
using namespace std;
int sg(int x){
    if(x % 8 == 0) return (x - 1);
    if((x+1) % 8 == 0) return (x + 1);
    return x;
}
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 0, tmp;
        for(int i = 0; i < n; i ++){
            cin>>tmp;
            ans ^= sg(tmp);
        }
        switch(ans){
            case 0: cout<<"Second player wins."<<endl;  break;
            default:cout<<"First player wins."<<endl;   break;
        }
    }
    return 0;
}
