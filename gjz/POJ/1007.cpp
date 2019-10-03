#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int a[1005];//存放数组  
int rr[1005];//辅助数组，额外开销 
int n, ans;
void build(int l,int r){
	int mid=(l+r)/2;
	if(l==r) return;//只有一个数的时候返回 
	build(l,mid);//不断分割 
	build(mid+1,r); 
	int x=l,y=mid+1,z=l;
	while(x<=mid&&y<=r)	{
		if(a[x]<a[y])
		rr[z++]=a[x++];
		else 
		rr[z++]=a[y++],ans+=mid-x+1;//逆序对 
	}
	while(x<=mid)
	rr[z++]=a[x++];
	while(y<=r)
	rr[z++]=a[y++];
	for(int i=l;i<=r;i++)
		a[i]=rr[i];
}
int getrev(string s){
    ans = 0;
    for(int i = 0; i < s.size(); i ++){
        a[i] = s[i];
    }
    build(0, s.size() - 1);
    return ans;
}

struct note{
    string s;
    int rev;
    note(): s(""), rev(0){}
    void set(){
        rev = getrev(s);
    }
};

bool operator<(note a, note b){
    return a.rev < b.rev;
}

note nt[1000];

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < k; i ++){
        cin>>nt[i].s;
        nt[i].set();
    }
    sort(nt, nt + k);
    for(int i = 0; i < k; i ++){
        cout<<nt[i].s<<endl;
    }
    return 0;
}




