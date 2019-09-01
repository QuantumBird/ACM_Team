#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int sum[200];
int n;
int get_sum(int i, int j){
    if(i + j >= n)
        return get_sum(i, n - i - 1) + get_sum(0, i + j - n);
    return sum[i + j] - (i > 0? sum[i - 1]: 0);
}
int find_min(){
    int dp[200][200];
    for(int i = 0; i < 200; i ++){
        for(int j = 0; j < 200; j ++){
            dp[i][j] = (i == j? 0: INT_MAX);
        }
    }
    for(int j = 1; j < n; j ++){
        for(int i = 0; i < n; i ++){
            for(int k = 0; k < j; k ++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[(i + k + 1)%n][j - k - 1] + get_sum(i, j));
        }
    }
    return dp[0][n - 1];
}
int find_max(){
    int dp[200][200];
    for(int i = 0; i < 200; i ++){
        for(int j = 0; j < 200; j ++){
            dp[i][j] = 0;
        }
    }
    for(int j = 1; j < n; j ++){
        for(int i = 0; i < n; i ++){
            for(int k = 0; k < j; k ++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[(i + k + 1)%n][j - k - 1] + get_sum(i, j));
        }
    }
    return dp[0][n - 1];
}
int main(){
    while(cin>>n){
        sum[0] = 0;
        for(int i = 0; i < n; i ++){
            int inp;
            cin>>inp;
            sum[i] = (i == 0? inp: sum[i - 1] + inp);
        }
        cout<<find_min()<<" "<<find_max()<<endl;
    }
    return 0;
}

