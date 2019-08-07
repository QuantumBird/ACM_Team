#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int ans, cnt = 0;
        for(int i = 0; i < n; i ++){
            int t;
            cin>>t;
            if(cnt == 0){
                ans = t;
                cnt ++;
            }else{
                if(ans == t){
                    cnt ++;
                }else{
                    cnt --;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}