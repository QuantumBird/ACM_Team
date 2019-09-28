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
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 105;
int pre[maxn];
int mp[maxn][maxn];
int find(int i){
    return i==pre[i]?i:find(pre[i]);
}