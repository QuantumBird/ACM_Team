#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 1;
struct node{
    int id;
    int rank;
} nte[maxn];
bool cmp(node a, node b){
    return a.rank > b.rank;
}
int n, m;
int main(){
    //cin>>n>>m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++){
        int tmp;
        //cin>>tmp;
        scanf("%d", &tmp);
        nte[tmp].id = tmp;
        nte[tmp].rank = n - i;
    }
    int rank_tmp = n + 1;
    for(int i = 0; i < m; i ++){
        int tmp;
        //cin>>tmp;
        scanf("%d", &tmp);
        nte[tmp].rank = rank_tmp;
        rank_tmp ++;
    }
    sort(nte + 1, nte + n + 1, cmp);
    //printf("%d", nte[1].id);
    for(int i = 1; i <= n; i ++){
        //cout<<nte[i].id<<" ";
        printf("%d ", nte[i].id);
    }
    //cout<<endl;
    printf("\n");
    return 0;
}