#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt_one, pos_two, pre_zero, cnt_zero;
	cnt_one = pos_two = pre_zero = cnt_zero = 0;
	bool flag = false;
	for(int i = 0; i < s.size(); i ++){
		if(flag == false && s[i] == '2'){
			flag = true;
			pos_two = i;
		}
		if(s[i] == '1') cnt_one ++;
		if(flag == false && s[i] == '0') pre_zero ++;
		if(s[i] == '0') cnt_zero ++; 
	}
	if(cnt_zero == s.size()){
		cout<<s<<endl;
		return 0;
	}
	for(int i = 0; i < pre_zero; i ++) cout<<"0";
	for(int i = 0; i < cnt_one; i ++) cout<<"1";
	for(int i = pos_two; i < s.size(); i ++){
		if(s[i] == '1') continue;
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}

