#include <iostream>
using namespace std;
const int maxn = 41;
int fib[maxn];
int main(){
    fib[1] = 1;
    for(int i = 2; i < maxn; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int T;
    cin>>T;
    while(T --){
        int n;
        cin>>n;
        cout<<fib[n]<<endl;
    }
    return 0;
}

