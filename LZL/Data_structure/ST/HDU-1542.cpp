//简单的扫描线板子题　注意线段树维护的是区间　在求segt的值时注意转化
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility> 
#include<cstring>
#include<cstdio>
using namespace std;

#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
const int maxn = 505;
int lazy[maxn<<2];
double x[maxn<<2],sum[maxn<<2];
int T,top,flag;
double x1,x2,yy1,yy2,ans; //y1这个命名竟然出现问题了

void init(){
    memset(sum,0,sizeof(sum));
    memset(lazy,0,sizeof(lazy));
    memset(x,0,sizeof(x));
    top = 0;
    ans = 0;
}
struct node{
    int ss;//区分上下边
    double l,r,y;
    node() = default;
    node(int s,double ll,double rr,double yy):ss(s),l(ll),r(rr),y(yy){}
    bool operator<(node &a){
        return y < a.y;
    }
};
node dian[maxn<<2];

void push_up(int q,int l,int r){
    if(lazy[q]){
        sum[q] = x[r+1] - x[l];//还是下面说的问题　线段树是维护一个区间　这里的值要转化到点上　所以r+1
    }else if(l == r){
        sum[q] = 0;
    }else{
        sum[q] = sum[lson] + sum[rson];
    }
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        lazy[q]+=k;
        push_up(q,l,r);
        return;
    }
    int m = mid;
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs  > m) update(rson,m+1,r,lhs,rhs,k);
    push_up(q,l,r);
}

int main(){
    while(cin >> T && T){
        init();
        cout << "Test case #" << ++flag << endl;
        for(int i=0;i<T;++i){
            cin >> x1 >> yy1 >> x2 >> yy2;
            x[top] = x1;
            dian[top++] = {1,x1,x2,yy1};
            x[top] = x2;
            dian[top++] = {-1,x1,x2,yy2};
        }
        sort(dian,dian+top);
        sort(x,x+top);
        int k = 1;
        for(int i=1; i<top; i++){
            if(x[i] != x[i-1])
                x[k++] = x[i];
        }
        for(int i=0;i<top-1;++i){
            int l = lower_bound(x,x+k,dian[i].l) - x;
            int r = lower_bound(x,x+k,dian[i].r) - x - 1;
            //这里值得思考和注意　线段树上维护的是一个线段　所以r要减一
            update(1,0,k-1,l,r,dian[i].ss);
            ans += (sum[1] * (dian[i+1].y - dian[i].y));
        }
        cout << "Total explored area: ";
        printf("%.2f\n\n",ans);
    }
    return 0;
}