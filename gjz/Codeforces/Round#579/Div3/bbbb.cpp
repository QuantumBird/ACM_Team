#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t --){
        map<int, int> cnt;
        vector<int> note;
        int n;
        cin>>n;
        n *= 4;
        for(int i = 0; i < n; i ++){
            int inp;
            cin>>inp;
            cnt[inp] ++;
            note.push_back(inp);
        }
        bool f = true;
        for(map<int, int>::iterator it = cnt.begin();\
                it != cnt.end(); \
                it ++){
            if(it->second & 1){
                f = false;
                break;
            }
            for(int i = it->second; i; i -= 2)
                note.push_back(it->first);
        }
        if(f == false)
            cout<<"NO"<<endl;
        else{
            int len = note.size();
            bool flag = true;
            sort(note.begin(), note.end());
            int tmp = note[0]*note[len - 1];
            for(int i = 0; i < len / 2; i ++){
                if(note[i]*note[len - 1 - i] != tmp){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}

