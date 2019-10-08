#include <iostream>
 
using namespace std;
int m,n,x,y,nn;
int main()
{
    cin>>m>>n>>x>>y>>nn;
    if(x>y) swap(m,n),swap(x,y);
    cout<<max(nn-m*(x-1) - n*(y-1),0)<<" "<<min(m,nn/x) + (nn-min(m,nn/x)*x)/y ;
    return 0;
}
