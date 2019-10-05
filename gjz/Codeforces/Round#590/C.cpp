#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int pipe[maxn][2];

void checkBlock(bool (& state)[4], int type){
    switch(type){
        case 1:
        case 2:{
            for(int i = 0; i < 4; i ++){
                state[i] = state[i] || state[(i + 2) % 4];
            }
        }; break;
        case 3:
        case 6:{
            state[2] = state[1] || state[3];
            state[3] = state[3] || state[0];
        }; break;
        case 4:
        case 5:{
            state[2] = state[1] || state[3];
            state[1] = state[1] || state[0];
        }
    }
}

void judge(bool a, bool b, int atype, int btype, bool & ansa, bool & ansb){
    bool mid = false;
    bool tmp[4];
    memset(tmp, false, sizeof(tmp)); tmp[0] = true;
    if(a == true){
        checkBlock(tmp, atype);
        mid = tmp[3];
        ansa = tmp[2];
        memset(tmp, false, sizeof(tmp)); tmp[0] = b;
        tmp[1] = mid;
        checkBlock(tmp, btype);
        ansb = tmp[2];
    }else if(b == true){
        checkBlock(tmp, btype);
        mid = tmp[1];
        ansb = tmp[2];
        memset(tmp, false, sizeof(tmp)); tmp[0] = a;
        tmp[3] = mid;
        checkBlock(tmp, atype);
        ansa = tmp[2];
    }else{
        ansa = ansb = false;
    }
}

int main(){
    int T, n;
    cin>>T;
    while(T --){
        cin>>n;
        for(int i = 0; i < n; i ++)
            cin>>pipe[i][0];
        for(int i = 0; i < n; i ++)
            cin>>pipe[i][1];
        bool tmpa, tmpb;
        tmpa = true;
        tmpb = false;
        for(int i = 0; i < n; i ++){
            judge(tmpa, tmpb, pipe[i][0], pipe[i][1], tmpa, tmpb);
        }
        if(tmpb){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
