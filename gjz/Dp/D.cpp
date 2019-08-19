#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int dp[200][200];
bool is_match(int i, int j){
    if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
        return true;
    return false;
}
int get_ans(){
    memset(dp, 0, sizeof(dp));
    int len = s.length();
    for(int i = len - 1; i >= 0; i --){
        for(int j = i + 1; j < len; j ++){
            if(is_match(i, j))
                dp[i][j] = dp[i + 1][j - 1] + 1;
            for(int k = i; k < j; k ++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    return 2*dp[0][len - 1];
}
int main(){
    while(cin>>s, s != "end"){
        cout<<get_ans()<<endl;
    }
    return 0;
}


