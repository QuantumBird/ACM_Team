#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 250;
bool a[maxn], b[maxn];
int arr[maxn], brr[maxn];
int an, bn;
void init(){
    memset(a, false, sizeof(a));
    memset(b, false, sizeof(b));
}
void input(){
    init();
    cin>>an;
    for(int i = 0; i < an; i ++){
        cin>>arr[i];
        a[arr[i]] = true;
    }
    cin>>bn;
    for(int i = 0; i < bn; i ++){
        cin>>brr[i];
        b[brr[i]] = true;
    }
}
void find_ans(){
    for(int i = 0; i < an; i ++){
        for(int j = 0; j < bn; j ++){
            int t = arr[i] + brr[j];
            if(a[t] == false && b[t] == false){
                cout<<arr[i]<<" "<<brr[j]<<endl;
                return ;
            }
        }
    }
}
int main(){
    input();
    find_ans();
    return 0;
}

