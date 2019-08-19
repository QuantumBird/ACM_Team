#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int dpa[200][200], dpb[200][200];
int sum[200];
int find_min(int s, int t){
    if(s == t)
        return dpa[s][t] = 0;
    if(dpa[s][t] != INT_MAX)
        return dpa[s][t];
    for(int k = s; k < t; k ++)
        dpa[s][t] = min(dpa[s][t], find_min(s, k) + find_min(k + 1, t) + sum[t] - sum[s - 1]);
    return dpa[s][t];
}
int find_max(int i, int j){
    if(i == j)
        return dpb[i][j] = 0;
    if(dpb[i][j] != 0)
        return dpb[i][j];
    for(int k = i; k < j; k ++)
        dpb[i][j] = max(dpb[i][j], find_max(i, k) + find_max(k + 1, j) + sum[j] - sum[i - 1]);
    return dpb[i][j];
}

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < 200; i ++){
            for(int j = 0; j < 200; j ++){
                dpb[i][j] = 0;
                dpa[i][j] = (i == j? 0: INT_MAX);
            }
        }
        sum[0] = 0;
        for(int i = 1; i <= n; i ++){
            int inp;
            cin>>inp;
            sum[i] = sum[i - 1] + inp;
        }
        cout<<find_min(1, n)<<" "<<find_max(1, n)<<endl;
    }
    return 0;
}

