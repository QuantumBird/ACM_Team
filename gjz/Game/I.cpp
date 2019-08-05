#include <iostream>
#include <climits>
using namespace std;
const int N = 4000000+1000;
int a[N], b[N];
int n, k, t;
int main(){
    cin>>t;
    while(t--){
        cin>>k>>n;
        int i, j;
        i = j = 0;
        a[0] = b[0] = 1;
        while(a[i] < n){
            i ++;
            a[i] = b[i - 1] + 1;
            while(a[j + 1]*k < a[i]) j++;
            if(a[j]*k < a[i])
                b[i] = b[j] + a[i];
            else
                b[i] = a[i];
        }
        cout<<(n - i)<<endl;
    }
    return 0;
}