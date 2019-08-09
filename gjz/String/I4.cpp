#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef unsigned long long ull;
ull seed = 9731;
struct HashElem{
    ull hash_value;
    string s;
} _magic[100100], _index[100100], tmp_he;
bool operator<(HashElem h1, HashElem h2){
    return h1.hash_value < h2.hash_value;
}
int main(){
    string _index_s, _magic_s;
    char c;
    int n;
    while(true){
        cin>>c;
        if(c == '@') break;
        if(c != '[') continue;
        ull ite = seed, hash_val = 0;
        _index_s.clear();
        while(true){
            cin>>c;
            if(c == ']') break;
            hash_val += c * ite;
            _index_s.push_back(c);
            ite *= ite;
        }
        getchar();
        getline(cin, _magic_s);
        _magic[n].hash_value = hash_val;
        _magic[n].s = _magic_s;
        ite = seed, hash_val = 0;
        for(int i = 0; i < _magic_s.length(); i ++){
            hash_val += _magic_s[i] * ite;
            ite *= ite;
        }
        _index[n].hash_value = hash_val;
        _index[n].s = _index_s;
        n ++;
    }
    int t;
    cin>>t;
    sort(_index, _index + n);
    sort(_magic, _magic + n);
    getchar();
    while(t --){
        string inp;
        getline(cin, inp);
        ull hash_val, ite;
        hash_val = 0;
        ite = seed;
        if(inp[0] == '['){
            for(int i = 1; i < inp.length() - 1; i ++){
                hash_val += inp[i] * ite;
                ite *= ite;
            }
            int pos;
            tmp_he.hash_value = hash_val;
            pos = lower_bound(_magic, _magic + n, tmp_he, tmp_he) - _magic;
            if(_magic[pos].hash_value != hash_val){
                cout<<"what?"<<endl;
            }else{
                cout<<_magic[pos].s<<endl;
            }
        }else{
            for(int i = 0; i < inp.length(); i ++){
                hash_val += inp[i] * ite;
                ite *= ite;
            }
            int pos;
            tmp_he.hash_value = hash_val;
            pos = lower_bound(_index, _index + n, tmp_he) - _index;
            if(_index[pos].hash_value != hash_val){
                cout<<"what?"<<endl;
            }else{
                cout<<_index[pos].s<<endl;
            }
        }
    }
    return 0;
}
