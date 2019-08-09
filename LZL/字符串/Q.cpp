//字符串哈希
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<cstring>
#include<sstream>
using namespace std;

typedef unsigned long long ull;
ull Hash[16000000+10];
ull base[16000000+10];
const int prime=13331;
int ans;

ull BKDRhash(int l,int r)
{
    return Hash[r]-Hash[l-1]*base[r-l+1];
}

int main()
{
    
}