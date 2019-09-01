#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 50;
int k, n, m;
struct Mat{
    int m[maxn][maxn];
    Mat(){}
    void zeros(){
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                m[i][j] = 0;
    }
    void ones(){
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                m[i][j] = (i == j? 1: 0);
    }
};
Mat operator*(const Mat & a, const Mat & b){
    Mat ans;
    ans.zeros();
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            for(int k = 0; k < n; k ++)
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k]*b.m[k][j]) % m;
    return ans;
}
Mat operator^(Mat a, int n){
    Mat ans;
    ans.ones();
    while(n){
        if(n & 1)
            ans = ans*a;
        n >>= 1;
        a = a*a;
    }
    return ans;
}
Mat operator+(const Mat & a, const Mat & b){
    Mat ans;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            ans.m[i][j] = (a.m[i][j] + b.m[i][j]) % m;
    return ans;
}
Mat sum(Mat a, int n){
    int t;
    Mat ans, pre;
    if(n == 1)
        return a;
    t = n / 2;
    pre = sum(a, t);
    ans = pre + (pre*(a^(t)));
    if(n & 1)
        ans = ans + (a^n);
    return ans;
}
int main(){
    Mat ans, M;
    cin>>n>>k>>m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin>>M.m[i][j];
            M.m[i][j] %= m;
        }
    }
    ans = sum(M, k);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cout<<ans.m[i][j]<<(j == n - 1? "\n": " ");
    return 0;
}



