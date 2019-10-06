#include<bits/stdc++.h>
using namespace std;

int book[10];

int main(){
    cin >> book[0]>> book[1] >> book[2] >> book[3];
    int sum = book[0]+book[1]+book[2]+book[3];
    if(sum%2==1) cout << "NO\n";
    else{
        for(int i=1;i<4;++i){
            if(book[i]+book[0]==sum/2){
                cout << "YES\n";
                return 0;
            }
        }
        for(int i=0;i<4;++i){
            if(book[i]==sum/2){
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }
    return 0;
}