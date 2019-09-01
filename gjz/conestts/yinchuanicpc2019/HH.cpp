#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
class Moster{
public:
    ll hp;
    ll attack;
    ll times;
    double rate;
    Moster(){}
};
bool operator<(Moster a, Moster b){
    if(a.rate != b.rate)
        return a.rate < b.rate;
    return a.attack > b.attack;
}
istream & operator>>(istream & in, Moster & m){
    in>>m.hp>>m.attack;
    ll tmp = m.hp;
    for(int i = 1;tmp >= 0; i ++){
        tmp -= i;
        m.times ++;
    }
    m.rate = double(m.times) / m.attack;
    return in;
}
Moster arr[maxn];
int main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; i ++){
        memset(arr, 0, sizeof(arr));
        int n;
        cin>>n;
        for(int i = 0; i < n; i ++)
            cin>>arr[i];
        sort(arr, arr + n);
        ll cnt = 0;
        ll sum = 0;
        for(int i = 0; i < n; i ++){
            sum += arr[i].attack*cnt;
            cnt += arr[i].times;
            sum += arr[i].attack*arr[i].times;
        }
        cout<<"Case #"<<i<<": "<<sum<<endl;
    }
    return 0;
}
