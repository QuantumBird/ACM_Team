#include <iostream>
#include <algorithm>
using namespace std;
int pos[3];
int main(){
    int d;
    for(int i = 0; i < 3; i ++)
        cin>>pos[i];
    cin>>d;
    sort(pos, pos + 3);
    int ans = ((pos[2] - pos[1]) >= d? 0: d - (pos[2] - pos[1])) + \
              ((pos[1] - pos[0]) >= d? 0: d - (pos[1] - pos[0]));
    cout<<ans<<endl;
    return 0;
}

