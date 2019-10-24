//轮廓线　可以当做板子
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
const int maxn = 10000+10;

struct line{
    int y1,y2;
    int h,flag;
    line() = default;
    line(int yy1,int yy2,int hh,int f):y1(yy1),y2(yy2),h(hh),flag(f){}
    bool operator<(const line & a)const{
        if(h == a.h) return flag > a.flag; //考虑到边重合的情况　需要入边在最前面
        return h < a.h;
    }
};

struct node{
    int len;//区间被覆盖的长度
    int sum;//区间的不连续线段数
    int lazy;
    bool lr,rr;//左右边界是否被覆盖
};
node segt[maxn<<2];
line book[maxn];
int x1,x2,yy1,y2,top,ans;
int n;
vector<int> vec;

void init(){
    memset(segt,0,sizeof(segt));
    memset(book,0,sizeof(book));
    vec.clear();
    ans = 0,top = 0;
}

void push_up(int q,int l,int r){
    if(segt[q].lazy > 0){//这很重要
        segt[q].len = vec[r+1] - vec[l];
        segt[q].lr = segt[q].rr = true;
        segt[q].sum = 1;
        return;
    }
    if(l == r){
        segt[q].len = segt[q].sum = segt[q].lazy= 0;
        segt[q].rr = segt[q].lr = false;
        return;
    }

    segt[q].len = segt[lson].len + segt[rson].len;
    segt[q].sum = segt[lson].sum + segt[rson].sum - (segt[lson].rr & segt[rson].lr);
    segt[q].lr = segt[lson].lr;
    segt[q].rr = segt[rson].rr;
}

void update(int q,int l,int r,int lhs,int rhs,int k){
    if(l>=lhs && r<=rhs){
        segt[q].lazy += k;
        push_up(q,l,r);
        return;
    }
    int m = mid;
    if(lhs <= m) update(lson,l,m,lhs,rhs,k);
    if(rhs  > m) update(rson,m+1,r,lhs,rhs,k);
    push_up(q,l,r);
}

int main(){
    while(cin >> n){
        init();
        for(int i=0;i<n;++i){
            cin >> x1 >> yy1 >> x2 >> y2;
            vec.push_back(yy1);
            book[top++] = {yy1,y2,x1,1};
            vec.push_back(y2);
            book[top++] = {yy1,y2,x2,-1};
        }
        sort(vec.begin(),vec.end());
        sort(book,book+top);
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        std::size_t len = vec.size();
        int lines = 0,Old_Len = 0;
        for(int i=0;i<top;++i){
            int l = lower_bound(vec.begin(),vec.end(),book[i].y1) - vec.begin();
            int r = lower_bound(vec.begin(),vec.end(),book[i].y2) - vec.begin() - 1;
            update(1,0,len-1,l,r,book[i].flag);
            if(i>=1) ans+=(lines*2*(book[i].h-book[i-1].h));
            ans += abs(segt[1].len - Old_Len);
            Old_Len = segt[1].len;
            lines = segt[1].sum;
        }
        cout << ans << endl;
    }
    return 0;
}