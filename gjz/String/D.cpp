#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e6 + 10;
int n[MAXN];
char s[MAXN];
int len;
void get_ans(void){
    n[0] = n[1] = 0;
    for(int i = 1; i < len; i ++){
        int j = n[i];
        while(j && s[i] != s[j]) j = n[j];
        n[i + 1] = (s[i] == s[j])? j + 1: 0;
    }
}
int main(){
    int cas = 1;
    while(cin>>len, len){
        cin>>s;
        cout<<"Test case #"<<cas<<endl;
        cas ++;
        get_ans();
        for(int i = 2; i <= len; i ++){
            int lng = i - n[i];
            if(n[i] > 0 && i % lng == 0){
                cout<<i<<" "<<(i/lng)<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}