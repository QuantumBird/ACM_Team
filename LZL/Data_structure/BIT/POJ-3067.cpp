#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<cstdio>
using namespace std;

//把所有　cin 换成　scanf　就过了
//注意做树状数组的题的时候注意求sum时该不该减1
typedef long long ll;
typedef pair<ll,ll> pa;
ll q,N,M,K;
const int maxn = 1010*1010;
pa book[maxn];
ll flag,num;
ll low[maxn];

ll lowbit(ll i){
    return i&-i;
}

void add(ll i){
    while(i<1010){
        low[i] += 1;
        i+=lowbit(i);
    }
}

ll sum(ll i){
    int ans = 0;
    while(i > 0){
        ans += low[i];
        i -= lowbit(i);
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        num = 0;
        memset(low,0,sizeof(low));
        cin >> N >> M >> K;
        for(int i=0;i<K;++i){
            cin >> book[i].first >> book[i].second;
        }
        sort(book,book+K,greater<pa>());
        for(int i=0;i<K;++i){
            num += sum(book[i].second - 1);
            add(book[i].second);
        }
        cout << "Test case "<< ++flag << ": " << num << endl;
    }
    return 0;
}