#include <iostream>
using namespace std;
const int maxn = 1e9 + 1;
int st[maxn];
bool mark[maxn];
int n, q;
int findc(int id){
    while(st[id] != id)
        id = st[id];
    return (id > n? -1: id);
}
void zipPath(int s, int f){
    int pre = s;
    s = st[s];
    while(st[s] != s){
        st[pre] = f;
        pre = s;
        s = st[s];
    }
}
int main(){
    cin>>n>>q;
    for(int i = 0; i <= n; i ++)
        st[i] = i;
    while(q --){
        int opt, idx;
        cin>>opt>>idx;
        if(opt == 1){
            mark[idx] = true;
            if(idx < n){
                if(mark[idx + 1] == false){
                    st[idx] = idx + 1;
                }else{
                    st[idx] = idx + 1;
                    zipPath(idx, findc(idx + 1));
                }
            }else{
                st[idx] = -1;
            }
        }else{
            if(mark[idx] == false)
                cout<<idx<<endl;
            else if(st[idx] == -1)
                cout<<-1<<endl;
            else 
                cout<<findc(idx)<<endl;
        }
    }
    return 0;
}
