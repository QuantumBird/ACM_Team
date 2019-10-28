#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<unordered_map>
#include<cstring>
using namespace std;
string book;
string res;
int flag;
int ans;
int number;
int tmpc;
int Answer__;

void kmp(int *next)
{
    int n=res.size();
    int i=0,j=-1;
    next[0]=-1;
    while(i<n)
    {
        if(j==-1 || res[i]==res[j])
        {
            i++;j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

void solve(int *next)
{
    int i=0,j=0;
    int n=res.size();
    int m=book.size();
    while(i<m)
    {
        if(j==-1 || book[i]==res[j])
        {
            i++;j++;
            if(j==n)
            {
            	flag++;
            	tmpc--;
                //cout << "pi pei \n";
            	if(!tmpc)
            	{
            		Answer__=i-n+1;
            		return;
				}
			}
        }else{
            j=next[j];
        }
    }
}

int main()
{
    int q;
    scanf("%d",&q);
    int tmpa,tmpb;
    int m,n;
    while(q--)
    {
    	Answer__=0;
	   flag=0;
	   int next[10000+10];
	   cin >> m >> n;
	   cin >> book;
	   for(int i=0;i<n;i++)
	   {
	   	    cin >> tmpa >> tmpb >> tmpc;
		   res = book.substr(tmpa-1,tmpb-tmpa+1); //child
           //cout << res << endl;
		   kmp(next);
		   solve(next);
		   if(tmpc) Answer__=-1;
		   printf("%d\n",Answer__);
		   memset(next,0,sizeof(next));
		}
	}
    return 0;
}


 
