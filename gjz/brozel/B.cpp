#include <iostream>
#include <string>
using namespace std;

int getAns(string & s){
    int h, o, c;
    h = o = c = 0;
    for(int i = 0; i < s.length(); i ++){
        switch(s[i]){
            case 'H': h ++; break;
            case 'O': o ++; break;
            case 'C': c ++; break;
        }
    }
    return h + o*16 + c*12;
}

int main(){
    int T;
    cin>>T;
    while(T --){
        string s;
        cin>>s;
        cout<<getAns(s)<<endl;
    }
    return 0;
}


