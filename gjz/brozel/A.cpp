#include <iostream>
using namespace std;

long getAns(long a, long b){
    int m = max(a, b);
    int n = min(a, b);
    return m*2 + n;
}

int main(){
    int T;
    cin>>T;
    while(T --){
        long a, b;
        cin>>a>>b;
        cout<<getAns(a, b)<<endl;
    }
    return 0;
}

