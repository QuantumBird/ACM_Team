#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
namespace matrix{
    const int maxn = 5;
    struct Mat{
        int m[maxn][maxn];
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

