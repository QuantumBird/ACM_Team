#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAXN = 1000000 + 10;
int nextv[MAXN];
int get_ans(string & a, string & b){
    memset(nextv, 0, sizeof(nextv));
    nextv[0] = -1;
    int k = -1;
    int j = 0;
    while(j < b.length() - 1){
        if(k == -1 || b[j] == b[k]){
            j ++;
            k ++;
            if(b[j] != b[k]){
                nextv[j] = k;
            }else{
                nextv[j] = nextv[k];
            }
        }else{
            k = nextv[k];
        }
    }
    int ans = 0;
    int i = 0;
    j = 0;
    while(i < a.length() && b.length()){
        if(j == -1 || a[i] == b[j]){
            i ++;
            j ++;
        }else{
            j = nextv[j];
        }
        if(j == b.length()){
            ans ++;
            j = 0;
        }
    }
    return ans;
}
int main(){
    string a, b;
    while(cin>>a, a != "#"){
        cin>>b;
        cout<<get_ans(a, b)<<endl;
    }
    return 0;
}