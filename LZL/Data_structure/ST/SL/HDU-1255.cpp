//线段树维护区间覆盖大于二的区间数　算是板子题　需要引入一个数组len2 维护区间大于2的覆盖数
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
const int maxn = 2000+10;
int lazy[maxn<<2];
double x[maxn<<2];
double len2[maxn<<2];
double len1[maxn<<2];
int T,top,flag,q;
double x1,x2,yy1,yy2,ans; //y1这个命名竟然出现问题了

void init(){
    memset(len1,0,sizeof(len1));
    memset(len2,0,sizeof(len2));
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

//lazy标记不能下推的原因是是因为后面有-1　只能保留lazy标记
void push_up(int q,int l,int r){//把这个当板子
    if(lazy[q] >= 2){
        len2[q] = len1[q] = x[r+1] - x[l];
    }else if(lazy[q] == 1){
        len1[q] = x[r+1] - x[l];
        if(l == r) len2[q] = 0;//仔细想　当出现l==r的时候为一条线
        else len2[q] = len1[lson] + len1[rson]; //这句是精髓
        //这一句解决了我的问题　即子区间为1 父区间也为1 如何使子区间覆盖数为2的区间为1
    }else{
        if(l == r) len1[q] = len2[q] = 0;
        else {
            len1[q] = len1[lson] + len1[rson];
            len2[q] = len2[lson] + len2[rson];
            //每个len中维护的是自己　与父节点没有任何关系　所以可以这样更新
        }
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
    scanf("%d",&q);
    while(q--){
        init();
        scanf("%d",&T);
        for(int i=0;i<T;++i){
            scanf("%lf %lf %lf %lf",&x1,&yy1,&x2,&yy2);
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
            update(1,0,k-1,l,r,dian[i].ss);
            ans += (len2[1] * (dian[i+1].y - dian[i].y));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}