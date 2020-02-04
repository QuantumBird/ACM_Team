#include<bits/stdc++.h>
using namespace std;

int h,m,sum;
int main(){
    cin >> sum;
    while(sum--){
        cin >> h >> m;
        cout << (23-h)*60+60-m << endl;
    }
    return 0;
}