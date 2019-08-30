#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> rx;
    vector<int> ry;
    int k,x,y,cnt=0,l=0,i;
    while(cin>>k){
    	for(y=k+1;y<=2*k;y++){
    		if((k*y)%(y-k)==0&&(k*y)/(y-k)>=y){
    			x=(k*y)/(y-k);
    			cnt++;
    			rx.push_back(x);
    			ry.push_back(y);
    			l++;
    		}
    	}
    	cout<<cnt<<"\n";
    	for(i=0;i<l;i++){
    		printf("1/%d = 1/%d + 1/%d\n",k,rx[i],ry[i]);
    	}
    	cnt=0;
    	rx.clear();
    	ry.clear();
    	l=0;
    }	
    return 0;
}

