#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
using namespace std;

namespace{
    using ll = long long;
    ll Left,Right,ans;
    string str;
    ll tmpa,tmpb,tmpc;
    ll sum_B,sum_S,sum_C;
    ll sum_a,sum_b,sum_c;
    ll sum;
}

bool judge(ll mid){
    ll a = mid*sum_B;
    ll b = mid*sum_S;
    ll c = mid*sum_C;
    ll need_B = max(ll(0),a-tmpa);
    ll need_S = max(ll(0),b-tmpb);
    ll need_C = max(ll(0),c-tmpc);
    ll Spend = need_B * sum_a + need_S * sum_b + need_C * sum_c;
    if(Spend <= sum) return true;
    else return false;
}

int main(){
    cin >> str;
    for(auto x : str){
        if(x=='B') ++sum_B;
        else if(x=='S') ++sum_S;
        else if(x=='C') ++sum_C;
    }
    cin >> tmpa >> tmpb >> tmpc;
    cin >> sum_a >> sum_b >> sum_c;
    cin >> sum;
    Left = 0;Right = 1e13;
    while(Left<=Right){
        ll mid = Left + ((Right - Left) / 2);
        if(judge(mid)){
            ans = mid;
            Left = mid + 1;
        }else{
            Right = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}