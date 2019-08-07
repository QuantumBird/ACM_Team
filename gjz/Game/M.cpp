#include <iostream>
using namespace std;
const int MAXN = 101;
int a[MAXN];
int main(){
    int n;
    while(cin>>n, n){
        int txor = 0;
        for(int i = 0; i < n; i ++){
            cin>>a[i];
            txor = txor^a[i];
        }
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            int t = txor^a[i];
            if(a[i] > t)
                cnt ++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}