#include <iostream>
#include <climits>
using namespace std;
const int maxn = 5;
typedef unsigned long long ull;
struct Mat{
    ull m[maxn][maxn];
    Mat(){}
    ull * operator[](int i){
        return m[i];
    }
};
const int size = 2;
void zeros(Mat & a){
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            a[i][j] = 0;
}
void ones(Mat & a){
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            a[i][j] = (i == j? 1: 0);
}
Mat operator*(Mat a, Mat b){
    Mat ans;
    zeros(ans);
    for(int i = 0; i < size; i ++)
        for(int j = 0; j < size; j ++)
            for(int k = 0; k < size; k ++)
                ans[i][j] += a[i][k] * b[k][j];
    return ans;
}
Mat operator^(Mat a, int n){
    Mat ans;
    ones(ans);
    while(n){
        if(n & 1)
            ans = ans*a;
        a = a*a;
    }
    return ans;
}
int main(){
    int T, kase = 0;
    cin>>T;
    while(T --){
        ull p, q, n;
        cin>>p>>q>>n;
        ull tmp = ULLONG_MAX - q + 1;
        Mat cst, mit;
        zeros(cst);
        zeros(mit);
        mit[1][1] = p;
        mit[1][2] = p*p + 2*tmp;
        mit[1][3] = q;
        if(n == 0)
            cout<<2<<endl;
        else if(n == 1)
            cout<<p<<endl;
        else if(n == 2)
            cout<<(p*p + 2*tmp)<<endl;
        else{
            cst[1][1] = 0;
            cst[2][1] = 1;
            cst[1][2] = tmp;
            cst[2][2] = p;
            cout<<(mit*(cst^(n - 2)))[1][2]<<endl;
        }
    }
    return 0;
}


