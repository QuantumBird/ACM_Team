#include <iostream>
#include <string>
using namespace std;
string sc2c(int s){
    if(90 <= s && s <= 100) return "A";
    if(80 <= s && s <= 89)  return "B";
    if(70 <= s && s <= 79)  return "C";
    if(60 <= s && s <= 69)  return "D";
    if(0 <= s && s <= 59)   return "E";
    return "Score is error!";
}
int main(){
    int s;
    while(cin>>s){
        cout<<sc2c(s)<<endl;
    }
    return 0;
}

