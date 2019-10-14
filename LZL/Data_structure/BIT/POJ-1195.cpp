#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility> 
#include<cstring>
#include<cstdio>
using namespace std;

const int INF = 32800;
class BIT{
    private:
        int len;
        int tree[1050][1050];
        int lowbit(int i){
            return i&-i;
        }
        int add(int x,int y,int w){
            for(int i=x;i<=len;i+=lowbit(i)){
                for(int j=y;j<=len;j+=lowbit(j)){
                    tree[i][j]+=w;
                }
            }
        }
        int sum(int x,int y){
            int ans = 0;
            for(int i=x;i>0;i-=lowbit(i)){
                for(int j=y;j>0;j-=lowbit(j)){
                    ans+=tree[i][j];
                }
            }
            return ans;
        }
        public:
            BIT(){
                memset(tree,0,sizeof(tree));
            }
            void run(int flag){
                int a,b,c,d;
                if(!flag){
                    cin >> len;
                }else if(flag == 1){
                    cin >> a >> b >> c;
                    add(a+1,b+1,c);
                }else if(flag == 2){
                    cin >> a >> b >> c >> d;
                    int ans = sum(c+1,d+1)+sum(a,b)-sum(c+1,b)-sum(a,d+1);
                    cout << ans << endl;
                }
            }
};

int main(){
    std::ios::sync_with_stdio(false);
    int tmp = 0;
    BIT M;
    while(cin >> tmp && tmp != 3){
        M.run(tmp);
    }
    return 0;
}