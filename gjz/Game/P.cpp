#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1000 + 1;
int sg[MAXN];
bool note[MAXN];
int mex(void){
    for(int i = 0; i < MAXN; i ++){
        if(note[i] == false){
            return i;
        }
    }
    return MAXN;
}
int main(){
    sg[0] = 0;
    for(int i = 0; i < MAXN; i ++){
        memset(note, false, sizeof(note));
        int t = 1;
        while(i >= t){
            note[sg[i - t]] = true;
            t = t * 2;
        }
        sg[i] = mex();
    }
    int n;
    while(cin>>n){
        if(sg[n] != 0)
            cout<<"Kiki\n";
        else
            cout<<"Cici\n";
    }
    return 0;
}