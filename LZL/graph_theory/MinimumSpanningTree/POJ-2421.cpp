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
#include<cstdio>
#include<cstring>
using namespace std;

int q;
typedef pair<int,int> pa;
int mp[105][105];
int tmp,sum,tmpa,tmpb;
int flag[105];
int low[105];
const int INF = 0x3f3f3f3f;

int Prim(){
    flag[1] = true;
    int ans = 0;
    int p = 1;
    for(int i=1;i<=sum;++i){
        low[i] = mp[1][i];
    }
    for(int i=2;i<=sum;++i){
        int MAX = INF;
        for(int j=1;j<=sum;++j){
            if(!flag[j] && low[j]<MAX){
                MAX = low[p=j];
            }
        }
        ans += MAX;
        flag[p] = 1;
        for(int j=1;j<=sum;++j){
            if(!flag[j] && mp[p][j]<low[j])
                low[j] = mp[p][j];
        }
    }
    return ans;
}

void init(){
    memset(flag,0,sizeof(flag));
}

int main(){
    while(cin >> q ){
        init();
        sum = q;
        for(int j=1;j<=sum;++j){
            for(int i=1;i<=sum;++i){
                cin >> tmp;
                if(i==j) continue;
                mp[i][j] = tmp;
            }
        }
        cin >> q;
        while(q--){
            cin >> tmpa >> tmpb;
            mp[tmpa][tmpb] = 0;
            mp[tmpb][tmpa] = 0;
        }
        cout << Prim() << endl;
    }
    return 0;
}