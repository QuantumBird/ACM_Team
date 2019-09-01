#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int r, c;
int movx[] = {-1, 1, 0, 0};
int movy[] = {0, 0, -1, 1};
int dp[maxn][maxn], arr[maxn][maxn];
bool check(int x, int y){
    if(x >= 0 && x < r && y < c && y >= 0)
        return true;
    return false;
}
int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    int ret = 1;
    for(int k = 0; k < 4; k ++){
        int tx = x + movx[k];
        int ty = y + movy[k];
        if(check(tx, ty) && arr[x][y] > arr[tx][ty])
            ret = max(ret, dfs(tx,ty) + 1);
    }
    dp[x][y] = ret;
    return ret;
}
int main(){
    while(cin>>r>>c){
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < c; j ++)
                cin>>arr[i][j];
        int ans = 0;
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < c; j ++)
                ans = max(dfs(i, j) + 1, ans);
        cout<<(ans - 1)<<endl;
    }
    return 0;
}
