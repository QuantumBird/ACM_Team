#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1000 + 1;
int sg[MAXN];
int fb[20];
bool mark[MAXN];
int mex(void){
    for(int i = 0; i < MAXN; i ++)
        if(mark[i] == false)
            return i;
    return MAXN;    // useless, just to throw off the warning of compiler
}
int main(){
    fb[0] = fb[1] = 1;
    for(int i = 2; i < 20; i ++)
        fb[i] = fb[i - 1] + fb[i - 2];
    sg[0] = 0;
    for(int i = 1; i < MAXN; i ++){
        memset(mark, false, sizeof(mark));
        for(int j = 1; fb[j] <= i; j ++){
            mark[sg[i - fb[j]]] = true;
        }
        sg[i] = mex();
    }
    int m, n, p, res;
    while(cin>>m>>n>>p,(m||n||p)){
		res = sg[m]^sg[n]^sg[p];		
		if(res)				
			puts("Fibo");
		else
			puts("Nacci");
	}
    return 0;
}