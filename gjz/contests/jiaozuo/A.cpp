#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	map<int, string> dict;
	dict[0] = "Typically Otaku";
	dict[1] = "Eye-opener";
	dict[2] = "Young Traveller";
	dict[3] = "Excellent Traveller";
	dict[4] = "Contemporary Xu Xiake";
	int T;
    while(cin>>T){
        while(T --){
            int inp, ans;
            ans = 0;
            for(int i = 0; i < 4; i ++){
                cin>>inp;
                if(inp != 0){
                    ans ++;
                }
            }
            ans = min(ans, 4);
            cout<<dict[ans]<<endl;
        }
    }
	return 0;
}

