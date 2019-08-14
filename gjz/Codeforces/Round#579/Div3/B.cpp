#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const int lenmax = 1e4 + 10;
int nlen[lenmax];
vector<int> note;

int main() {
    int q;
    cin>>q;
    while(q --){
        memset(nlen, 0, sizeof(nlen));
        note.clear();
        int n;
        cin>>n;
        for(int i = 0; i < 4*n; i ++){
            int inp;
            cin>>inp;
            if(nlen[inp] == 0){
                note.push_back(inp);
            }
            nlen[inp] ++;
        }
        bool ans = true;
        long long int tmp = 1;
        for(int i = 0; i < note.size(); i ++){
            if(nlen[note[i]] % 2 != 0){
                ans = false;
                break;
            }
            nlen[note[i]] /= 2;
            for(int i = 0; i < nlen[note[i]]; i ++){
                tmp = tmp * note[i];
            }
        }
        if(ans == false){
            cout<<"NO"<<endl;
            continue;
        }else {
            int s = pow(double(tmp), 1.0 / double(n));
            if(pow(s, n) == tmp)
                cout<<"YES"<<endl;
            else{
                bool f = false;
                for(int i = s - 2; i < s + 3; i ++){
                    if(pow(i, n) == tmp){
                        f = true;
                        break;
                    }
                }
                if(f)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
