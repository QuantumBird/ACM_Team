#include <iostream>
using namespace std;
typedef long long ll;
ll fib[60];
int main(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 60; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int n;
    while(cin>>n)
        cout<<fib[n]<<endl;
    return 0;
}

