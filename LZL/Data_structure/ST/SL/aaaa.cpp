#include<iostream>
#include<cmath>
using namespace std;
const int INF = pow(2,31);
int book[40];
int judge(int tmp){
    int ans = 0;
    for(int i=30;i>=0;--i){
        if(tmp>=book[i]){
            cout << tmp << " " << book[i] << endl;
            tmp-=book[i];
            ++ans;
        }
    }
    return ans;
}
int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x>>1) + (x&1);
}
int main(){
    for(int i=0;i<=31;++i){
        book[i] = pow(2,i);
    }
    cout << INF << endl;
    cout << bitcount(31) << endl;
}