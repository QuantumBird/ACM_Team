#include<bits/stdc++.h>
using namespace std;
int q,m,n;
string str;
int flag;
map<string,int>mp;

bool judge(string &st){
    if(st[0] != 'l') return true;
    else return false;
}

void init(){
    mp["int"] = 4;
    mp["double"] = 8;
    mp["float"] = 4;
    mp["bool"] = 1;
    mp["char"] = 1;
    mp["__int128"] = 16; 
}

int num(string &strr){
    string st = strr;
    string str = st.substr(st.find('['));
    str.erase(str.begin());
    str.erase(--str.end());
    str.erase(--str.end());
    istringstream rec(str);
    int x = 0;
    rec >> x;
    return x;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> q;
    init();
    while(q--){
        cin >> m;
        int sum = 0;
        for(int i=0;i<m;++i){
            int base = 0;
            int mul = 1;
            for(int j=0;j<3;++j){
                cin >> str;
                if(j == 0 && judge(str)){
                    base+=mp[str];
                    continue;
                }
                if(j == 1){
                    if(str == "double") base += 16;
                    else if(str == "long") base += 8;
                    else{
                        if(str.find('[') != string::npos){
                            mul = num(str);
                        }
                        break;
                    }
                    continue;
                }
                if(j == 2 && str.find('[') != string::npos){
                    mul = num(str);
                }
            }
            sum += base*mul;
        }
        cout <<"Case #"<< ++flag << ": " <<(sum+1023)/1024<< endl;;
    }
    return 0;
}