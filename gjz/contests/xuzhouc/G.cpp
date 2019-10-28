#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Counter{
    bool mark[26];
    int ans;
public:
    Counter(){
        for(int i = 0; i < 26; i ++) mark[i] = false;
        ans = 0;
    }
    void add(char c){
        if(c >= 'a' && c <= 'z'){
            if(mark[c - 'a'] == false)
                ans ++;
            mark[c - 'a'] = true;
        }
    }
    int get_ans(){
        return ans;
    }
};
int Manacher(string s){
    string res="$#";
    for(int i=0;i<s.size();++i){
        res+=s[i];
        res+="#";
    }
    vector<int> P(res.size(),0);
    int mi=0,right=0;   //mi为最大回文串对应的中心点，right为该回文串能达到的最右端的值
    int maxLen=0,maxPoint=0;    //maxLen为最大回文串的长度，maxPoint为记录中心点
    int ans = 0;//s.size();
    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     //关键句，文中对这句以详细讲解
        
        while(res[i+P[i]]==res[i-P[i]])
            ++P[i];
        
        if(right<i+P[i])    //超过之前的最右端，则改变中心点和对应的最右端
        {
            right=i+P[i];
            mi=i;
        }
        int plus = 0;
        Counter cnt;
        for(int j = 0; j < P[i]; j ++){
            cnt.add(res[i + j]);
            plus += cnt.get_ans();
        }
        ans += plus;
        cout<<res[i]<<" "<<P[i]<<" "<<plus<<endl;
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<Manacher(s)<<endl;
    return 0;
}