#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T --){
        int a, b;
        cin>>a>>b;
        if(__gcd(a, b) == 1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}

