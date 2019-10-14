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

string str1,str2;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> str1;
    str2 = str1;
    str2 = str2 + str1;
    int flag = 0;
    int ans = 1;
    int MAX = 1;
    int len = str2.length();
    for(int i=1;i<len;++i){
        if(str2[i] != str2[i-1]){
            ++ans;
            MAX = max(MAX,ans);
        }else{
            ans = 1;
        }
    }
    cout << min(len/2,MAX) << endl;
    return 0;
}