//单点更新　区间查询　结点存区间数值和

#include<bits/stdc++.h>
using namespace std;

#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
const int maxn = 50000+10;
int book[maxn];
int segt[maxn<<2];
int T,m,n;
int flag;

void init(){
    memset(book,0,sizeof(book));
    memset(segt,0,sizeof(segt));
}

void push_up(int q){
    segt[q] = segt[lson] + segt[rson];
}

void build(int q,int l,int r){
    if(l == r){
        segt[q] = book[l];
        return;
    }
    int m = mid;
    build(lson,l,m);
    build(rson,m+1,r);
    push_up(q);
}

void update_add(int q,int l,int r,int number,int k){
    if(l == r){
        segt[q] += k;
        return;
    }
    int m = mid;
    if(number <= m) update_add(lson,l,m,number,k);
    else update_add(rson,m+1,r,number,k);
    push_up(q);
}

void update_sub(int q,int l,int r,int number,int k){
    if(l == r){
        segt[q] -= k;
        return;
    }
    int m = mid;
    if(number <= m) update_sub(lson,l,m,number,k);
    else update_sub(rson,m+1,r,number,k);
    push_up(q);
}

int query(int q,int l,int r,int lhs,int rhs){
    int sum = 0;
    if(l >= lhs && r <= rhs){
        sum += segt[q];
        return sum;
    }
    int m = mid;
    if(lhs<=m) sum+=query(lson,l,m,lhs,rhs);
    if(rhs>m) sum+=query(rson,m+1,r,lhs,rhs);
    return sum;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cout << "Case " << ++flag << ":\n"; 
        string str;
        cin >> m;
        init();
        for(int i=1;i<=m;++i){
            cin >> book[i];
        }
        build(1,1,m);
        while(cin >> str && str!="End"){
            if(str == "Query"){
                int tmpa=0,tmpb=0;
                cin >> tmpa >> tmpb;
                cout << query(1,1,m,tmpa,tmpb) << endl;
            }else if(str == "Add"){ 
                int tmpa=0,tmpb=0;
                cin >> tmpa >> tmpb;
                update_add(1,1,m,tmpa,tmpb);
            }else if(str == "Sub"){
                int tmpa=0,tmpb=0;
                cin >> tmpa >> tmpb;
                update_sub(1,1,m,tmpa,tmpb);
            }
        }
    }
    return 0;
}