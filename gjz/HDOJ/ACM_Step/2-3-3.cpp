#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e7 + 1;
double lg[maxn];
int get_ans(int n){
    double ans = 0;
    for(int i = 2; i <= n; i ++)
        ans = ans + log10(i);
    return int(ceil(ans));
}
int main(){
    //init();
    //cout<<"CMPL"<<endl;
    int T;
    cin>>T;
    while(T --){
        int n;
        cin>>n;
        //cout<<int(ceil(lg[n]))<<endl;
        cout<<get_ans(n)<<endl;
    }
    return 0;
}

