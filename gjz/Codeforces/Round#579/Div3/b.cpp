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
        long long int tmp = 1;
        for(int i = 0; i < 4*n; i ++){
            int inp;
            cin>>inp;
            if(nlen[inp] == 0){
                note.push_back(inp);
            }
            nlen[inp] ++;
            tmp *= inp;
        }
        bool ans = true;
        for(int i = 0; i < note.size(); i ++){
            if(nlen[note[i]] % 2 != 0){
                ans = false;
                break;
            }
//            nlen[note[i]] /= 2;
//            for(int i = 0; i < nlen[note[i]]; i ++){
//                tmp = tmp * note[i];
//            }
        }
        if(ans == false){
            cout<<"NO"<<endl;
            continue;
        }else {
            if(n == 1 || tmp == 1){
                cout<<"YES"<<endl;
                continue;
            }
            long long int m = tmp;
            bool f = true;
            for(int i = 2; i < m; i ++){
                if(tmp % i == 0){
                    int cnt = 0;
                    while(tmp % i == 0){
                        tmp /= i;
                        cnt ++;
                    }
                    if(cnt % n != 0){
                        f = false;
                        break;
                    }
                }
            }
            if(f == false){
                cout<<"NO"<<endl;
            }else {
                int pa = pow(double(m), 1.0 / double(2*n));
                bool fa = true;
                for(int i = 0; i < note.size(); i ++){
                    if(pa % note[i]){
                        fa = false;
                        break;
                    }
                }
                if(fa){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
