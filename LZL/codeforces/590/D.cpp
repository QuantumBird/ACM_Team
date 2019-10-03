#include<bits/stdc++.h>
using namespace std;
//这道题告诉我区间操作不一定是线段树　好好学习吧　少年
int q,m,n,l,r;
char ch;
set<int>se[26];
int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i=0;i<len;++i){
        se[str[i]-'a'].insert(i+1);
    }
    cin >> q;
    while(q--){
        scanf("%d",&m);
        if(m==1){
            scanf("%d %c",&n,&ch);
            se[str[n-1]-'a'].erase(n);
            str[n-1] = ch;
            se[ch-'a'].insert(n);
        }else{
            int ans = 0;
            scanf("%d %d",&l,&r);
            for(int i=0;i<26;++i){
               auto pi = se[i].lower_bound(l);
               if(pi!=se[i].end() && *pi<=r) ++ans;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}