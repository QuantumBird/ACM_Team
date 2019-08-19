#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, m, a;
    cin>>n>>m>>a;
    long long int tn = ceil(double(n)/a);
    long long int tm = ceil(double(m)/a);
    cout<<tn*tm<<endl;
    return 0;
}

