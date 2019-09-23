#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
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

int x[8]={2,1,-1,-2,-2,-1,1,2};
int y[8]={1,2,2,1,-1,-2,-2,-1};

int vis[10][10];
int m,n;

void show(){
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            if(j==1) vis[i][j]<10?cout << " " <<vis[i][j] : cout << vis[i][j]; 
            else vis[i][j]<10?cout << "  " <<vis[i][j] : cout << " " << vis[i][j]; 
        }
        putchar('\n');
    }
}

int solve(int a,int b,int steps){
    if(steps == 65){
        show();
        exit(1);
    }
    for(int i=0;i<8;++i){
        int xx = a+x[i];
        int yy = b+y[i];
        if(xx>=1 && xx<=8 && yy>=1 && yy<=8 && vis[xx][yy]==0){
            vis[xx][yy]=steps;
            solve(xx,yy,steps+1);
            vis[xx][yy]=0;
        }
    } 
}

int main(){
    cin >> m >> n;
    vis[m][n] = 1;
    solve(m,n,2);
    return 0;
}