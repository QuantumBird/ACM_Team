#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
using LL=long long;

LL T,ha,hb,aa,ab,x,y,z,L,R;
char s1[100005],s2[100005];

inline LL cal(LL x, LL y){
	return (x+y)*(y-x+1)/2;
}

LL f(LL x){
	LL L=0,R=1E9,M;
	while(L<R){
		M=L+R>>1;
		if(cal(1,M)<x)
			L=M+1;
		else
			R=M;
	}
	return L;
}

LL get_sta(int sp, int ep, int limit){
	LL L=sp,R=ep;
	while(L<R){
		int M=L+R+1>>1;
		if(cal(M,ep)<limit)
			R=M-1;
		else
			L=M;
	}
	return L;
}

bool check(LL sum, LL pos, LL x, LL L, LL R){
	if(sum+pos>R)
		return false;
	L-=sum+pos;
	R-=sum+pos;
	if(L<=0)
		return true;
	LL sta=get_sta(pos+1,x,L),q=cal(sta,x),p=cal(pos+1,x-sta+1+pos);
	return p<=R;
}

void greedy(char *s, LL L, LL R, LL x, LL z, char c){
	LL sum=0;
	for(LL i=1;i<=x;i++)
		if(check(sum,i,x,L,R))
			s[i]='A',sum+=i;
		else
			s[i]='B';
	for(LL i=x+1;i<=z;i++)
		s[i]=c;
	s[z+1]='\0';
}

int main(){
	scanf("%lld",&T);
	while(T--){	
		scanf("%lld%lld%lld%lld",&ha,&hb,&aa,&ab);
		x=f(ha);
		y=f(hb);
		z=f(ha+hb);
		if(z*ab+x*aa<=z*aa+y*ab){
			R=cal(1,z)-hb;
			L=ha;
			greedy(s1,L,R,x,z,'B');
			if(z*ab+x*aa<z*aa+y*ab)
				printf("%lld ",z*ab+x*aa),puts(s1+1);
		}
		if(z*ab+x*aa>=z*aa+y*ab){
			L=ha-(cal(1,z)-cal(1,y));
			R=cal(1,y)-hb;
			greedy(s2,L,R,y,z,'A');
			if(z*ab+x*aa>z*aa+y*ab)
				printf("%lld ",z*aa+y*ab),puts(s2+1);
		}
		if(z*ab+x*aa==z*aa+y*ab)
			printf("%lld ",z*aa+y*ab),puts(strcmp(s1+1,s2+1)>0?s2+1:s1+1);
	}
	return 0;
}
