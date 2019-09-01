#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 101;
int note[maxn][maxn][11];
int main(){
    int n, q, c;
    while(cin>>n>>q>>c){
        memset(note, 0, sizeof(note));
        for(int i = 0; i < n; i ++){
            int x, y, k;
            cin>>x>>y>>k;
            note[x][y][k] ++;
        }
        for(int i = 0; i < maxn; i ++){
            for(int j = 0; j < maxn; j ++){
                for(int k = 0; k <= c; k ++){
                    note[i][j][k] += (note[i - 1][j][k] + note[i][j - 1][k] - note[i - 1][j - 1][k]);
                }
            }
        }
        for(int i = 0; i < q; i ++){
            int t, x, y, xx, yy;
            cin>>t>>x>>y>>xx>>yy;
            int ans = 0;
            for(int i = 0; i <= c; i ++){
                int k = i;
                int val = (t + i) % (c + 1);
                int tmp = note[xx][yy][k] + note[x - 1][y - 1][k] - note[x - 1][yy][k] - note[xx][y - 1][k];
                ans += val * tmp;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
