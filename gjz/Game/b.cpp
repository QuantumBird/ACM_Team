#include <iostream>
#include <algorithm>
using namespace std;
bool judge(int a, int b){
    if(a % b == 0 || a > 2*b) return true;
    return !judge(b, a - b);
}
int main(){
    int a, b;
    while(cin>>a>>b, a != 0 && b != 0){
        if(judge(max(a, b), min(a, b))){
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }
    }
    return 0;
}