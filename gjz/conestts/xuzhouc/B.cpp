#include <iostream>
using namespace std;
const int maxn = 1e9 + 1;
bool note[maxn];
int find(int id, int n){
    while(note[id] == true)
        id ++;
    return (id > n? -1: id);
}
int main(){
    int n, q;
    cin>>n>>q;
    while(q --){
        int op, idx;
        cin>>op>>idx;
        if(op == 1)
            note[idx] = true;
        else
            cout<<find(idx, n)<<endl;
    }
    return 0;
}
