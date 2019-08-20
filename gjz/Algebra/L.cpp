#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 20;
int deg[maxn];
struct Mat{
    ll m[maxn][maxn];
    int size;
    Mat(int s): size(s){}
    Mat(){}
    ll * operator[](int i){
        return m[i];
    }
};

ll det(Mat & a){
    if(a.size == 2)
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    ll ans = 0;
    for(int i = 0; i < a.size; i ++){
        Mat t;
        t.size = a.size - 1;
        for(int p = 0; p < t.size; p ++){
            for(int q = 0; q < t.size; q ++){
                t[p][q] = (q < i? a[p + 1][q]: a[p + 1][q + 1]);
            }
        }
        if(i & 1)
            ans -= a[0][i]*det(t);
        else
            ans += a[0][i]*det(t);
    }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while(T --){
        int sz, q;
        cin>>sz>>q;
        Mat m;
        m.size = sz;
        for(int i = 0; i < m.size; i ++)
            for(int j = 0; j < m.size; j ++)
                m[i][j] = 0;
        memset(deg, 0, sizeof(deg));
        while(q --){
            int a, b;
            cin>>a>>b;
            deg[a - 1] ++;
            deg[b - 1] ++;
            m[a - 1][b - 1] = -1;
            m[b - 1][a - 1] = -1;
        }
        if(sz == 1 || sz == 2){
            cout<<1<<endl;
            continue;
        }
        for(int i = 0; i < m.size; i ++)
            m[i][i] = deg[i];
        m.size -= 1;
        cout<<abs(det(m))<<endl;
    }
    return 0;
}

