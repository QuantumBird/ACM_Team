#include <iostream>
#include <algorithm>
using namespace std;
bool judge(int m, int n){
    int a = max(m, n);
    int b = min(m, n);
    bool ans = true;
    while(true){
        if(a % b == 0 || a > 2*b)
            return ans;
        a = a - b;
        int t = a;
        a = b;
        b = t;
        ans = !ans;
    }
}
int main(){
    int a, b;
    while(cin>>a>>b, a != 0 && b != 0){
        if(judge(a, b)){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }
    }
    return 0;
}