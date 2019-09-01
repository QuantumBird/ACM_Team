#include <iostream>
#include <queue>
using namespace std;
int a[51][51];
int b[51][51];
int x, y;
int cnt = 0;
vector<pair<int, int>> q;
const int movx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int movy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int check_remove(int i, int j){
    int ret = 0;
    for(int k = 0; k < 8; k ++){
        int tx = i + movx[k];
        int ty = j + movy[k];
        if(tx >= 0 && tx < x - 1 && ty >= 0 && ty < y - 1){
            if(a[tx][ty] + a[tx + 1][ty] + a[tx][ty + 1] + a[tx + 1][ty + 1] == 4){
                ret = b[tx][ty] + b[tx + 1][ty] + b[tx][ty + 1] + b[tx + 1][ty + 1];
                b[tx][ty] = b[tx + 1][ty] = b[tx][ty + 1] = b[tx + 1][ty + 1] = 0;
                q.push_back(pair<int, int>(tx, ty));
                return ret;
            }
        }
    }
    return ret;
}
int main(){
    cin>>x>>y;
    for(int i = 0; i < x; i ++){
        for(int j = 0; j < y; j ++){
            cin>>a[i][j];
            cin>>b[i][j];
            cnt += a[i][j];
        }
    }
    while(cnt){
        int tmp = cnt;
        for(int i = 0; i < x; i ++){
            for(int j = 0; j < y; j ++){
                if(b[i][j] == 1){
                    cnt -= check_remove(i, j);
                }
            }
        }
        if(tmp == cnt){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<q.size()<<endl;
    for(int i = 0; i < q.size(); i ++){
        cout<<q[i].first<<" "<<q[i].second<<endl;
    }
    return 0;
}