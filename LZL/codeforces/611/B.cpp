#include<bits/stdc++.h>
using namespace std;

int sum,x,y;

int main(){
    cin >> sum;
    while(sum--){
        cin >> x >> y;
        int T = 0;
        if(x%y > y/2) T = y/2;
        else T = x%y;
        cout << T+(x-(x%y)) << endl;
    }
    return 0;
}