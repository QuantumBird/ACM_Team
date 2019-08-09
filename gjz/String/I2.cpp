#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
int idx(char c){
    if(c == ' ') return 26;
    return (c - 'a');
}
char ridx(int id){
    if(id == 26) return char(' ');
    return char(id + 'a');
}
struct Node{
    int end_node;
    int father_node;
    char note_char;
    int next_node[27];
};
struct Tire{
    Node node[maxn];
    int nptr;
    Tire(){
        memset(node, 0, sizeof(node));
        nptr = 1;
    }
    int insert(string & s){
        int p = 1;
        int fthr = 1;
        bool mark;
        for(int i = 0; i < s.length(); i ++){
            mark = false;
            int ch = idx(s[i]);
            if(node[p].next_node[ch] == 0){
                node[p].next_node[ch] = ++ nptr;
                mark = true;
            }
            fthr = p;
            p = node[p].next_node[ch];
            if(mark){
                node[p].father_node = fthr;
                node[p].note_char = s[i];
            }
        }
        return p;
    }
    int query(string & s){
        int p = 1;
        for(int i = 0; i < s.length(); i ++){
            int ch = idx(s[i]);
            if(node[p].next_node[ch] == 0)
                return -1;
            p = node[p].next_node[ch];
        }
        return p;
    }
    void add_note(int node_id, int node_end){
        node[node_id].end_node = node_end;
    }
    string display(int node_id){
        string ans = "";
        int p = node_id;
        while(p != 1){
            ans += node[p].note_char;
            p = node[p].father_node;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
Tire index_dict;
Tire magic_dict;
int main(){
    int n,l,r;
    string s,index,magic;
    while(getline(cin,s) && s!="@END@"){
        l=s.find('['); r=s.find(']');
        index = s.substr(l+1,r-l-1);
        magic = s.substr(r+2,s.size()-r);
        int index_id = index_dict.insert(index);
        int magic_id = magic_dict.insert(magic);
        magic_dict.add_note(index_id, magic_id);
        index_dict.add_note(magic_id, index_id);
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
        if(id == -1){
            cout<<"what?"<<endl;
        }else{
            if(is_index){
                cout<<magic_dict.display(id)<<endl;
            }else{
                cout<<index_dict.display(id)<<endl;
            }
        }
    }
    return 0;
}