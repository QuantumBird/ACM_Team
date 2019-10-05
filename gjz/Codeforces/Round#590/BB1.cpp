#include <bits/stdc++.h>
using namespace std;
const int maxe = 1e9 + 1;
bool exist[maxe];
list<int> lst;
int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i ++){
        int inp;
        cin>>inp;
        if(exist[inp] == false){
            lst.push_front(inp);
            if(lst.size() > k){
                exist[*(--lst.end())] = false;
                lst.pop_back();
            }
            exist[inp] = true;
        }
    }
    cout<<lst.size()<<endl;
    for(list<int>::iterator it = lst.begin(); it != lst.end(); it ++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}