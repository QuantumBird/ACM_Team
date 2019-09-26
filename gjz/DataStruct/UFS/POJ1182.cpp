#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int ufs[maxn];
int rel[maxn];

void init(int size){
    for(int i = 0; i <= size; i ++){
        ufs[i] = i;
        rel[i] = 0;
    }
}

int find(int x){
    if(x == ufs[x]) return x;
    int tmp = ufs[x];
    ufs[x] = find(ufs[x]);
    rel[x] = (rel[x] + rel[tmp]) % 3;
    return ufs[x];
}

void merge(int r, int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        ufs[fx] = fy;
        rel[fx] = (rel[)

