#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50000 + 10;
int a[MAXN * 4] , n , m;

void build(int left , int right , int rt)
{
    if(left == right)
    {
        scanf("%d" , &a[rt]);
        return ;
    }
    int mid = (left + right) >> 1;
    build(left , mid , rt << 1);
    build(mid + 1, right , rt << 1 | 1);
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

int que(int x , int y , int left , int right ,int rt )
{
    if(left >= x && right <= y)
    {
        return a[rt];
    }
    int sum = 0;
    int mid = (left + right) >> 1;
    if(mid >= x)
    {
        sum += que(x , y , left , mid , rt << 1);
    }
    if(mid < y)
    {
        sum += que(x , y , mid + 1 , right , rt << 1 | 1);
    }
    return sum;
}

void add(int x , int k , int left , int right , int rt)
{
    if(left == right)
    {
        a[rt] += k;
        return;
    }
    int mid = (left + right) >> 1;
    if(mid < x)
        add(x , k , mid + 1, right , rt << 1 | 1);
    if(mid >= x)
        add(x , k , left , mid , rt << 1);
    a[rt] = a[rt << 1] + a[rt << 1 | 1];
}
int main()
{
    int T;
    cin >> T;
    int cas = 0;
    while(T --)
    {
        cas ++;
        scanf("%d" , &n);
        build(1 , n , 1);
        printf("Case %d:\n" , cas);
        string s;
        int x , y;
        cin >> s;
        while(s != "End")
        {
            scanf("%d  %d" , &x , &y);
            if(s == "Query")
            {
                printf("%d\n" , que(x , y , 1 , n , 1));
            }
            else if(s == "Add")
            {
                add(x , y , 1 , n , 1);
            }
            else if (s == "Sub")
            {
                add(x , -y , 1 , n , 1);
            }
            cin >> s;
        }
    }
    return 0;
}
