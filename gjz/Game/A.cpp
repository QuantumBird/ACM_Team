#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int T, n, k, cas = 1;
    cin>>T;
    while(T--){
        cin>>n>>k;
        printf("Case %d: ",cas++);
        if(n % 2 == 1 && k == 1) 
            cout<<"first"<<endl;
        else if(k >= n) 
            cout<<"first"<<endl;
        else 
            cout<<"second"<<endl;
    }
    return 0;
}
