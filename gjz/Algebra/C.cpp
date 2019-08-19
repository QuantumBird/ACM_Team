#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, m;
struct matrix{
    ll s[2][2];
    matrix() {}
    matrix(ll a, ll b, ll c, ll d){
        s[0][0] = a;
        s[0][1] = b;
        s[1][0] = c;
        s[1][1] = d;
    }
};
 
matrix operator*(matrix a, matrix b){
    matrix t = matrix(0, 0, 0, 0);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                t.s[i][j] = (t.s[i][j]+a.s[i][k]*b.s[k][j]+m)%m;
    return t;
}
 
matrix operator^(matrix p, int n){
    matrix q = matrix(1, 0, 0, 1);
    while(n){
        if(n&1) 
            q = p * q;
        p = p * p;
        n /= 2;
    }
    return q;
}
 
int main(){
    ll n;
    while(cin >> a >> b >> n >> m){
        matrix base = matrix(2*a, (b-a*a), 1, 0);
        ll c1 = 2*a%m;
        ll c2 = 2*(a*a+b)%m;
        if(n == 1) 
            printf("%lld\n", c1);
        else if(n == 2) 
            printf("%lld\n", c2);
        else{
            matrix ans = base^(n-2);
            printf("%lld\n", (ans.s[0][0]*c2+ans.s[0][1]*c1+m)%m);
        }
    }
    return 0;
}

