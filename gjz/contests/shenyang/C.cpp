#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
const int maxw = 1e5;
const int maxc = 1e5;
const int maxf = 1e8;
int w[maxw], c[maxc], f[maxf];
int main(){
    int m, V;
    while(cin>>m>>V){
        for(int i = 0; i < m; i ++)
            cin>>w[i]>>c[i];
        int ansa, ansb;
        ansa = ansb = INT_MAX;
        for(int i = 0; i < m; i ++){
            for(int j = w[i]; ; j ++){
                f[j] = max(f[j], f[j - w[i]] + c[i]);
                if(f[j] >= V){
                    if(j < ansa){
                        ansa = j;
                        ansb = f[j];
                    }
                    break;
                }
            }
        }
        cout<<ansa<<" "<<ansb<<endl;
    }
    return 0;
}

