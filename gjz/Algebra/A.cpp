#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
typedef unsigned long long ll;
namespace matrix{
    const int maxn = 5;
    struct Mat{
        ll m[maxn][maxn];
        Mat(){}
    };
    Mat zeros(){
        Mat ret;
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                ret.m[i][j] = 0;
        return ret;
    }
    Mat ones(){
        Mat ret;
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                ret.m[i][j] = (i == j? 1: 0);
        return ret;
    }
    Mat operator*(const Mat & a, const Mat & b){
        Mat ans = zeros();
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                for(int k = 0; k < maxn; k ++)
                    ans.m[i][j] += a.m[i][k] * b.m[k][j];
        return ans;
    }
    Mat operator^(Mat a, int n){
        Mat ans = ones();
        while(n){
            if(n & 1)
                ans = ans*a;
            a = a*a;
        }
        return ans;
    }
};
int main(){
    int T, kase = 0;
    cin>>T;
    while(T --){
        ll p, q, n;
        cin>>p>>q>>n;
        ll tmp = ULLONG_MAX - q + 1;
        matrix::Mat cst, mit;
        mit = matrix::zeros();
        mit.m[1][1] = p;
        mit.m[1][2] = p*p + 2*tmp;
        mit.m[1][3] = q;
        cout<<"Case "<<++kase<<": ";
        if(n == 0)
            cout<<2<<endl;
        else if(n == 1)
            cout<<p<<endl;
        else if(n == 2)
            cout<<(p*p + 2*tmp)<<endl;
        else{
            cst = matrix::zeros();
            cst.m[1][1] = 0;
            cst.m[2][1] = 1;
            cst.m[1][2] = tmp;
            cst.m[2][2] = p;
            cout<<(mit*(cst^(n - 2))).m[1][2]<<endl;
        }
    }
    return 0;
}

