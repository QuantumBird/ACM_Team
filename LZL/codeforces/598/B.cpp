#include<bits/stdc++.h>
using namespace std;

int q,m,n,ans;
int book[110];
int se[110];

int judge(int flag){
    for(int i=1;i<=n;++i){
        if(book[i] == flag && flag != i){
            for(int j=i;j>flag;--j){
                if(se[j]) continue;
                if(book[j]<book[j-1])  //这里有一个特殊样例 5 6 1 5 3 2 4 6
                //告诉我们在遇到某些情况时关系最好能写出来
                std::swap(book[j],book[j-1]);
                --ans;se[j]=1;if(!ans) return 1; 
            }
        }
    }
    return 0;
}

int main(){
    cin >> q;
    while(q--){
        memset(se,0,sizeof(se));
        int have_show = 0;
        cin >> n;
        ans = n-1;
        for(int i=1;i<=n;++i){
            cin >> book[i];
        }
        for(int i=1;i<=n;++i){
            if(judge(i)){
                for(int j=1;j<=n;++j) cout << book[j] << " ";
                cout << endl;
                have_show = 1;
                break;
            }
        }
        if(ans<=n-1 && !have_show){
            for(int j=1;j<=n;++j) cout << book[j] << " ";
            cout << endl;
        }
    }
    return 0;
}