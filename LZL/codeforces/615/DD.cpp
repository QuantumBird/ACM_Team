#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxx=4e5+10;

int xnow[maxx],vis[maxx];
int q,x,y,k,point,t;

int main(){
	scanf("%d%d",&q,&x);
	point=0;
	
	for(int ii=1;ii<=q;ii++){
		scanf("%d",&y);
		
		k=y%x;
		t=k+x*xnow[k];
		if(t<=maxx){
			vis[t]=1;
			xnow[k]++;
		}
		
		for(;point<=maxx;point++){
			if(vis[point]==0){
				break;
			}
		}
		
		printf("%d\n",point);
	} 
	
	return 0;
}
