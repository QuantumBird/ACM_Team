#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2e5;
const int seed = 131;
int hash_table[maxn];
int hash(string & s){
    int ans = 0;
    for(int i = 0; i < s.length(); i ++){
        ans = ans*seed + s[i];
    }
    return (ans % maxn);
}

