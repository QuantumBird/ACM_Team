#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 1;
char a[MAXN], b[MAXN];
int bnext[MAXN];
int m, n;
void build_next(void){
	memset(bnext, 0, sizeof(bnext));
	bnext[0] = -1;
	int k = -1;
	int j = 0;
	while(j < m - 1){
		if(k == -1 || b[j] == b[k]){
			j ++;
			k ++;
			if(b[j] != b[k])
				bnext[j] = k;
			else
				bnext[j] = bnext[k];
		}else{
			k = bnext[k];
		}
	}
}
int find(){
	int i = 0, j = 0;
	while(i < n && j < m){
		if(j == -1 || a[i] == b[j]){
			i ++;
			j ++;
		}else{
			j = bnext[j];
		}
	}
	if(j == m)
		return i - j + 1;
	else
		return -1;
}
int main(){
        cin>>a>>b;
        n = strlen(a);
        m = strlen(b);
		build_next();
		int p = find();
		int h = p - 1;
        int t = n - m - p + 1;
        cout<<max(h, t)<<endl;
	return 0;
}
