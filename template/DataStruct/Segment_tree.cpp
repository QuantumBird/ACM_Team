#define lson (q<<1)
#define rson (q<<1|1)
#define mid ((l+r)>>1)
#define maxn 200000

int segt[maxn<<2];//original array
int lazy[maxn<<2];//lazy tag

void push_down(int q,int l,int r);
void push_up(int q);
void build(int q,int l,int r);
void update(int q,int l,int r,int a,int b,int k);
int query(int q,int l,int r,int a,int b);

//q is where we are now
//l and r is Original range
//a and b is Target range
//k is not necessary,just a update condition.

void push_down(int q,int l,int r) //update lazy tag
{
    int m=mid;
    segt[lson]=(m-l+1)*lazy[q];
    segt[rson]=(r-m)*lazy[q];
    lazy[lson]=lazy[q];
    lazy[rson]=lazy[q];
    lazy[q]=0;
}

void build(int q,int l,int r)
{
    lazy[q]=0;
    if(l==r)
    {
        segt[q]=1;
        return;
    }
    int m=mid;
    build(lson,l,m);
    build(rson,m+1,r);
    segt[q]=segt[lson]+segt[rson];
}

//The others are calculated according to the problem.but we need uniform style.