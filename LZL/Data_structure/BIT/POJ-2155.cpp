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

const int maxn = 1010;
int q,m,n;
int tree[maxn][maxn];
char ch;
int x1,y1,x2,y2;

inline int lowbit(int i){
    return i&-i;
}

int add(int x,int y,int w){
    for(int i=x;i<=m;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            tree[i][j]+=w;
        }
    }
}

int sum(int x,int y){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans += tree[i][j];
        }
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    while(q--){
        memset(tree,0,sizeof(tree));
        cin >> m >> n;
        while(n--){
            cin >> ch;
            if(ch == 'C'){
                cin >> x1 >> y1 >> x2 >> y2;
                add(x2+1,y2+1,1);
                add(x1,y1,1);
                add(x1,y2+1,-1);
                add(x2+1,y1,-1);
            }else{
                cin >> x1 >> y1;
                cout << sum(x1,y1)%2 << endl;
            }
        }
        if(q) putchar('\n');
    }
    return 0;
}