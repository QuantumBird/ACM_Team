#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int t, a[maxn];
int main(){
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        a[0] = 0;
        sort(a + 1, a + n + 1);
        for(int i = n; i > 0; i = i - 2)
            sum ^= (a[i] - a[i-1] - 1);
        if(sum)
            printf("Georgia will win\n");
        else 
            printf("Bob will win\n");
    }
    return 0;
}
