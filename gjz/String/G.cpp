#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;
int main(){
    int ans = 0;
    int state = 0;
    char c;
    while(~scanf("%c", &c)){
        c = tolower(c);
        if(c == 'd')
            state = 1;
        else if(c == 'o' && state == 1)
            state = 2;
        else if(c == 'g' && state == 2)
            state = 3;
        else if(c == 'e' && state == 3){
            ans ++;
            state = 0;
        }else
            state = 0;
    }
    cout<<ans<<endl;
    return 0;
}
