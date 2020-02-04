#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5+10;

int q,x;
int flag[MAXN + 10];
int Temp;
int Count;
int sum;
int main(){
    cin >> q >> x;
    for(size_t i = 0; i < q; i++){
        cin >> Temp;
        int result = Temp%x;
        if(!flag[result]){
            Count++;
        }
        flag[result]++;
        if(Count == x){
            sum++;
            Count = 0;
            for(int i=0;i<x;++i){
                if(flag[i] > 1) Count++;
                --flag[i];
            }
        }
        for(int i = 0; i < x; ++i){
            if(!flag[i]){
                cout << sum*x + i << endl;
                break;
            }
        }
    }
    return 0;
}