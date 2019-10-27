#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct Moster{
    long long int hp;
    long int attack;
    long int time;
    double rate;
};
bool operator<(Moster a,Moster b){
    if(a.rate!=b.rate)
        return a.rate<b.rate;
    else
        return a.attack>b.attack;
}
istream & operator>>(istream & in, Moster & m){
    in>>m.hp>>m.attack;
    long long int tmp = m.hp;
    m.time=0;
    for(int j=1;;j++){
        tmp -= j;
        m.time++;
        if(tmp <= 0)
            break;
    }
    m.rate = double(m.time) / m.attack;
    return in;
}
Moster arr[maxn];
int main(){
    int t;
    std::ios::sync_with_stdio(false);
    cin>>t;
    for(int kase = 1; kase <= t; kase ++){
        memset(arr,0,sizeof(arr));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long int cnt = 0;
        long long int ans = 0;
        for(int i = 0; i < n; i ++){
            ans += arr[i].attack * cnt;
            cnt += arr[i].time;
            ans += arr[i].attack * arr[i].time;
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
    return 0;
} 
