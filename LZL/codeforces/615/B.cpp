#include <bits/stdc++.h>
using namespace std;
int n;
int T;
vector<std::pair<int,int>> vec(1010);
string result;
int prex,prey;
bool flag;

int main(){
    cin >> n;
    while(n--){
        flag = false;
        vec.clear();
        result.clear();
        prex = prey = 0;
        cin >> T;
        for(size_t i = 0; i < T; i++){
            int lhs,rhs;
            cin >> lhs >> rhs;
            vec.emplace_back(std::make_pair(lhs,rhs));
        }
        sort(vec.begin(),vec.end());
        for(int i = 0; i < vec.size();++i){
            auto z = vec[i];
            int x = z.first, y = z.second;
            if(y < prey){
                cout << "NO\n";
                flag = true;
                break;
            }
            string needU(x-prex, 'R');
            string needR(y-prey, 'U');
            result = result + needU;
            result = result + needR;
            prex = x;
            prey = y;
        }
        if(!flag){
            cout << "YES\n" << result << endl;
        }
    }
    return 0;
}