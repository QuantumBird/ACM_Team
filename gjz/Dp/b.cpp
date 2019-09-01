#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int dpa[200][200], dpb[200][200];
int sum[200], n;
int get_sum(int i, int j){
    if(i + j >= n)
        return get_sum(i, n - i - 1) + get_sum(0, i + j - n);
    return sum[i + j] - (i > 0? sum[i - 1]: 0);
}
int find_min(int i, int j){
    if(j == 0)
        return dpa[i][j] = 0;
    if(dpa[i][j] != INT_MAX)
        return dpa[i][j];
    for(int k = 0; k < j; k ++){
        dpa[i][j] = min(dpa[i][j], find_min(i, k)\
                find_min((i + k + 1) % n, j - k - 1)\
                + get_sum(i, i + j));
    }
    return dpa[i][j];
}
int find_max(int i, int j){
    if(j == 0)
        return dpb[i][j] = 0;
    if(dpb[i][j] != 0)
        return dpb[i][j];
    for(int k = 0; k < j; k ++){
        dpb[i][j] = max(dpb[i][j], find_max(i, k)\
                find_max((i + k + 1) % n, j - k - 1)\
                + get_sum(i, i + j));
    }
    return dpb[i][j];
}
int main(){
    while(cin>>n){

