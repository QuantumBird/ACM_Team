#include <iostream>
using namespace std;
int main(){
    int n, t, ans;
    while(cin>>n, n){
        ans = 0;
        for(int i = 0; i < n; i ++){
            cin>>t;
            ans = ans^t;
        }
        if(ans){
            cout<<"Rabbit Win!"<<endl;
        }else{
            cout<<"Grass Win!"<<endl;
        }
    }
}