#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
namespace{
    int a[100010];
    int n;
    long long flag;
    int Check(int median)
    {
        int t=0,i;
        long long sum=0;
        for(i=0;i<n;i++)
        {
            while( t<n && a[t]-a[i]<=median)
                t++;
            sum+=(t-i-1);
        }
        if(sum>=flag)
            return 1;
        return 0; 
    }
    int search()
    {
        int start=0;
        int end=1e9;
        int mid;
        while(end-start>1)
        {
            mid=(start+end)/2;
            if(Check(mid))
            end=mid;
            else
            start=mid;
        } 
        return end;
    }
}
int main()
{
	while(~scanf("%d",&n))
	{
		int ans,i,j,tmp;
		flag = (long long)n*(n-1)/2;
    	if(flag%2 == 0)
        	flag /=2;
    	else
        	flag = flag/2 + 1;
    	for(i=0;i<n;i++)
        	scanf("%d",&a[i]);
        sort(a,a+n);
        ans=search();
        printf("%d\n",ans);
	}
	return 0;
}