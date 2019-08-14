#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
double a[maxn][maxn];
map<string, int> note;
int n;
void init(){
    for(int i = 0; i < maxn; i ++)
        for(int j = 0; j < maxn; j ++)
            a[i][j] = 1;
    note.clear();
    cin>>n;

