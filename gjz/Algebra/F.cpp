#include <iostream>
using namespace std;
const int maxn = 25;
struct matrix{
    int mt[maxn][maxn];
    matrix(){
        for(int i = 0; i < maxn; i ++)
            for(int j = 0; j < maxn; j ++)
                mt[i][j] = 0;
    }
};
matrix operator*(const matrix & a, const matrix & b){
    matrix ret;
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            for(int k = 0; k < maxn; k ++)
                ret.mt[i][j] =(ret.mt[i][j] + a.mt[i][k] * b.mt[k][j])%1000;
    return ret;
}
matrix operator^(matrix m, int n){
    matrix ans;
    for(int i = 0; i < maxn; i ++)
        ans.mt[i][i] = 1;
    while(n){
        if(n & 1)
            ans = ans*m;
        m = m*m;
        n >>= 1;
    }
    return ans;
}
int main(){
    int n, m;
    while(cin>>n>>m, n || m){
        matrix mat;
        while(m --){
            int a, b;
            cin>>a>>b;
            mat.mt[a + 1][b + 1] = 1;
        }
        int q;
        cin>>q;
        while(q --){
            int a, b, k;
            cin>>a>>b>>k;
            matrix tmp = mat^k;
            cout<<tmp.mt[a + 1][b + 1]%1000<<endl;
        }
    }
    return 0;
}

