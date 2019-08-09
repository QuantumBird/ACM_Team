#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 2e6 + 1;
int hash(char c){
    if(c == ' ') return 26;
    return (c - 'a');
}
struct Node{
    int edn;
    int fap;
    char chr;
    int nxt[27];
};
struct Tire{
    Node node[maxn];
    int tot;
    Tire(){
        memset(node, 0, sizeof(node));
        tot = 1;
    }
    int insert(string & s){
        int p = 1;
        for(int i = 0; i < s.length(); i ++){
            int ch = hash(s[i]);
            if(node[p].nxt[ch] == 0){
                node[p].nxt[ch] = ++tot;
            }
            p = node[p].nxt[ch];
            node[p].chr = s[i];
        }
        return p;
    }
    void set_node(int nde, int end_node){
        node[nde].edn = end_node;
    }
    int query(string & s){
        int p = 1;
        for(int i = 0; i < s.length(); i ++){
            int ch = hash(s[i]);
            if(node[p].nxt[ch] == 0)
                return -1;
            p = node[p].nxt[ch];
        }
        return p;
    }
    string get_str(int end_node){
        string ans = "";

    }
}
Tire index_dict;
Tire magic_dict;
int main(){
    int n,l,r;
    string s,index,value;
    while(getline(cin,s) && s!="@END@"){
        l=s.find('['); r=s.find(']');
        index = s.substr(l+1,r-l-1);
        magic = s.substr(r+2,s.size()-r);
        int index_id = index_dict.insert(index);
        int magic_id = magic_dict.insert(magic);
        index_dict.set_node(index_id, magic_id);
        magic_dict.set_node(magic_id, index_id);
    }
    cin>>n;getline(cin,s);
    for(int i=0;i<n;i++)
    {
        bool is_index = false;
        getline(cin,s);
        if(s[0]=='['){
            s.erase(s.size()-1,1);
            s.erase(0,1);
            is_index = true;
        }
        int id;
        if(is_index)
            id = index_dict.query(s);
        else
            id = magic_dict.query(s);
        if(id == -1)
            cout<<"what?"<<endl;
        else
            cout<<display(id)<<endl;
    }
    return 0;
}