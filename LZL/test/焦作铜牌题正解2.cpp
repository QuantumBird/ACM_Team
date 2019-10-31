#include<bits/stdc++.h>
#include<tr1/unordered_map>
 
using namespace std;
 
using ll = long long;
using pa = pair<int,int>;
const int MAXN = 1e5+10;
 
vector<pa>G[MAXN*100];
int T,n,m,ct,cas;
int p1[MAXN<<1],p2[MAXN<<1];
int val[6005][6005];
bool vis[6005][6005],flag[10005];
void init(){
    for(int i=0;i<=6000;i++){
        for(int j=0;j<=6000;j++){
            if(i*i+j*j>1e7)break;
            if(i==j){
                if(flag[i])continue;
                else flag[i]=1;
            }
            G[i*i+j*j].push_back(pa(i,j));
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    init();
    cin >> T;
    while(T--){
        cout << "Case #" << ++cas << ":\n";
        cin >> n >> m;
        int x,y;ll w,k;
        for(int i=1;i<=n;i++){
            cin >> x >> y >> w;
            vis[x][y]=1;
            val[x][y]=w;
            p1[++ct]=x;p2[ct]=y;
        }
        ll lastans=0;
        while(m--){
            int op;
            cin >> op >> x >> y;
            x=(x+lastans)%6000+1;
            y=(y+lastans)%6000+1;
            if(op==1){
                cin >> w;
                vis[x][y]=1;
                val[x][y]=w;
                p1[++ct]=x;p2[ct]=y;
            }
            else if(op==2){
                vis[x][y]=val[x][y]=0;
            }
            else if(op==3){
                cin >> k >> w;
                for(int ii=0;ii<G[k].size();ii++){
                    pa p=G[k][ii];
                    int xx[3],yy[3];
                    xx[1]=x+p.first;yy[1]=y+p.second;
                    xx[2]=x-p.first;yy[2]=y-p.second;
                    for(int i=1;i<=2;i++){
                        if(xx[i]>6000||xx[i]<1)continue;
                        if(i==2&&xx[i]==xx[i-1])continue;
                        for(int j=1;j<=2;j++){
                            if(yy[j]>6000||yy[j]<1)continue;
                            if(j==2&&yy[j]==yy[j-1])continue;//防止重复
                            if(vis[xx[i]][yy[j]])val[xx[i]][yy[j]]+=w;
                        }
                    }
                }
            }
            else{
                cin >> k;
                ll ans=0;
                for(int ii=0;ii<G[k].size();ii++){
                    pa p=G[k][ii];
                    int xx[3],yy[3];
                    xx[1]=x+p.first;yy[1]=y+p.second;
                    xx[2]=x-p.first;yy[2]=y-p.second;
                    for(int i=1;i<=2;i++){
                        if(xx[i]>6000||xx[i]<1)continue;
                        if(i==2&&xx[i]==xx[i-1])continue;
                        for(int j=1;j<=2;j++){
                            if(yy[j]>6000||yy[j]<1)continue;
                            if(j==2&&yy[j]==yy[j-1])continue;
                            if(vis[xx[i]][yy[j]]) ans+=val[xx[i]][yy[j]];
                        }
                    }
                }
                cout << ans << endl;
                lastans=ans;
            }
        }
        for(int i=1;i<=ct;i++)//也是一种优化
            vis[p1[i]][p2[i]]=val[p1[i]][p2[i]]=0;
        ct=0;
    }
}
