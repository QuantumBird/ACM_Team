

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define LL long long
#define PI acos(-1.0)
const int maxn=2e6+100;
const int inf=0x3f3f3f3f;
using namespace std;
char s[maxn],ss[maxn];
int r[maxn];
int Manacher(int n){
	int cnt=0;
	ss[cnt++]='$';
	ss[cnt++]='#';
	for(int i=0;i<n;i++){
		ss[cnt++]=s[i];
		ss[cnt++]='#';
	}
	ss[cnt++]='/0';
	int pos=0,rx=0,ans=1; 	
	for(int i=1;i<cnt;i++){
		r[i]=rx>i?min(r[2*pos-i],rx-i):1;
		while(ss[i-r[i]]==ss[i+r[i]]) r[i]++;
		if(rx<i+r[i])
		{
			rx=i+r[i];
			pos=i;
		}
		if(ans<r[i]-1)
		  ans=r[i]-1;
	}
	return ans;
}
int main(void){
	int flag=0;
    while(~scanf("%s",s)){
    	if(flag) getchar();
    	else flag=1;
    	printf("%d\n",Manacher(strlen(s)));	
	}
 
    return 0;
}