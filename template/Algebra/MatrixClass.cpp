#include <iostream>
using namespace std;
const int maxn = 50;
struct Mat{
    int m[maxn][maxn];
    Mat(){}
    void ones(){
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                m[i][j] = (i == j? 1: 0);
    }
    void zeros(){
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                m[i][j] = 0;
    }
    int * operator[](int i){
        return m[i];
    }
};
Mat operator*(Mat a, Mat b){
    Mat ans;
    ans.zeros();
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            for(int k = 0; k < maxn; k ++)
                ans[i][j] = a[i][k]*b[k][j];
    return ans;
}
Mat operator+(const Mat & a, const Mat & b){
    Mat ans;
    ans.zeros();
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            ans[i][j] = a[i][j] + b[i][j];
    return ans;
}
Mat operator^(Mat a, int n){
    Mat ans;
    ans.ones();
    while(n){
        if(n & 1)
            ans = ans*a;
        a = a*a;
    }
    return ans;
}
ostream operator<<(ostream & out, Mat a){
    for(int i = 0; i < maxn; i ++){
        for(int j = 0; j < maxn; j ++){
            out<<a[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
int main(){
    Mat a;
    a.ones();
    cout<<a<<endl;
    return 0;
}
