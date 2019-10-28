#include<iostream>
#include<algorithm>
#include<string>
#define LL long long
using namespace std;
int main()
{
 
    string str;
    cin>>str;
 
    LL len=str.length();
    LL num_1=0;
    bool flag=true;
    for(LL i=0;i<len;i++)
    {
        if(str[i]=='1')
            num_1++;
        if(str[i]=='1'||str[i]=='2')
            flag=false;
    }
    LL pos;
    LL num_0=0;
    for(LL i=0;i<len;i++)
    {
        if(str[i]=='0')
            num_0++;
 
        if(str[i]=='2')
        {
            pos=i;
            break;
        }
    }
 
    if(flag)
    {
        cout<<str<<endl;
        return 0;
    }
 
    while(num_0--)
        cout<<'0';
    while(num_1--)
        cout<<'1';
 
    for(LL i=pos;i<len;i++)
    {
        if(str[i]=='1')
            continue;
        else
            cout<<str[i];
    }
    cout<<endl;
 
    return 0;
}

