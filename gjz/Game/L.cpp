#include <iostream>
using namespace std;
int main(){
    int n;
    int inp;
    while(cin>>n){
        int out=0;
        for(int i=1;i<=n;i++){
            cin>>inp;
            out ^= inp;
        }
        if(out == 0) 
            cout<<"John\n";
        else 
            cout<<"Brother\n";
    }
    return 0;
}
