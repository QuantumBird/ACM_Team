#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
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
        }
        if(ans == false){
            cout<<"NO"<<endl;
            continue;
        }else {
            bool bt = true;
            int tlen = note.size();
            sort(note.begin(), note.end());
            int tmp = note[0]*note[tlen - 1];
            for(int i = 0; i < tlen / 2; i ++){
                if(note[i]*note[tlen - i - 1] != tmp){
                    bt = false;
                    break;
                }
            }
            if(bt)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
