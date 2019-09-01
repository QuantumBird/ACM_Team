#include <iostream>
using namespace std;
int a[100];
int main(){
    a[1] = 3;
    a[2] = 7;
    for(int i = 3; i < 100; i ++)
        a[i] = a[i - 1]*2 + a[i - 2];
    int T;
    cin>>T;
    while(T --){
        int n;
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}

