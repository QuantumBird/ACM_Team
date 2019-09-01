#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 21;
int a[maxn];
int dp[maxn][2];
int dfs(int pos, int pre, int sta, bool limit){
    if(pos == -1) return 1;
    if(!limit && dp[pos][sta] != -1) return dp[pos][sta];
    int 
