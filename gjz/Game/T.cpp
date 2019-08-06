#include <iostream>
using namespace std;
int main(){
    int n, m;
    while(cin>>n>>m, n || m){
        if(n % 2 == 0 || m % 2 == 0)
            cout<<"Wonderful!"<<endl;
        else
            cout<<"What a pity!"<<endl;
    }
    return 0;
}
