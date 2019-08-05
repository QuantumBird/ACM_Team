#include <iostream>
using namespace std;
const int MAXN = 45 + 1;
int fib[MAXN];
int main(){
    int n;
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i < MAXN; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    while(cin>>n, n){
        bool flag = false;
		for(int i = 0; i < 45; i ++){
			if(fib[i] == n){
                flag = true;
                break;
            }
        }
		if(flag)
			cout<<"Second win\n";
		else
			cout<<"First win\n";
	}
    return 0;
}