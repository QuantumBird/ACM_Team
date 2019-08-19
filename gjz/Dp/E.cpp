//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int dp[200][200];
int get_ans(const string & s, int i, int j){
    if(i == j)
        return dp[i][j] = 0;
    if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
        dp[i][j] = get_ans(s, i + 1, j - 1) + 2;
    for(int k = i; k < j; k ++)
        dp[i][j] = max(dp[i][j], get_ans(s, i, k) + get_ans(s, k + 1, j));
    return dp[i][j];
}
int main(){
    string s;
    while(cin>>s, s != "end"){
        memset(dp, 0, sizeof(dp));
        cout<<get_ans(s, 0, s.size() - 1)<<endl;
    }
    return 0;
}

