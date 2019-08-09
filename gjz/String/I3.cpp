#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
typedef unsigned long long ll;
long long seed = 9731;
char s[40];
struct HashElem{
    ll num;
    string s;
    bool operator<(const HashElem x){
        return x.num < num;
    }
} a[100086], b[100086], exa;
int main(){
    string pos,pre;
    char c;
    int nn=0;
    while(true){
        scanf("%c",&c);
        if(c == '@') break;
        if(c != '[') continue;
        ll ss = seed, num = 0;
        pre.clear();
        while(true){
            scanf("%c",&c);
            if(c==']')  break;
            num += c * ss;
            pre.push_back(c);
            ss*=ss;
        }
        getchar();
        getline(cin, pos);
        a[nn].num = num;
        a[nn].s = pos;
        int l = pos.length();
        ss = seed, num = 0;
        for(int i = 0; i < l; i ++){
            num += pos[i] * ss;
            ss *= ss;
        }
        b[nn].num = num;
        b[nn].s = pre;
        nn ++;
    }
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    sort(a, a + nn);
    sort(b, b + nn);
    getchar();
    while(q--){
        getline(cin, pos);
        ll num = 0,ss = seed;
        int l=pos.length();
        if(pos[0]=='['){
            for(int i=1;i<l-1;i++){
                num+=ss*pos[i];
                ss*=ss;
            }
            int y;
            exa.num=num;//cout<<num<<endl;
            y=lower_bound(a,a+nn,exa)-a;
            if(a[y].num!=num){cout<<"what?"<<endl;}
            else cout<<a[y].s<<endl;
        }
        else{
            for(int i=0;i<l;i++){
                num+=ss*pos[i];
                ss*=ss;
            }
            int y;
 
            exa.num=num;
            y=lower_bound(b,b+nn,exa)-b;
            if(b[y].num!=num){cout<<"what?"<<endl;}
            else cout<<b[y].s<<endl;
        }
    }
}