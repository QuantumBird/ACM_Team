#include <iostream>
#include <stdio.h>
using namespace std;
 
const int M=100;
char s[M];
char ss[M];
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int num1=0,num2=0;
        if(s[0]=='R')
        {
            int i=1;
            while('0'<=s[i]&&s[i]<='9')
                num1=num1*10+s[i++]-'0';
            if(i>1&&s[i]=='C')
            {
                i++;
                while('0'<=s[i]&&s[i]<='9')
                    num2=num2*10+s[i++]-'0';
                //cout<<num2<<endl;
                int j=0;//,f=0;
                while(num2>0)
                {
                    ss[++j]=(num2-1)%26+'A';//可能出现最顶部出现1
                    //cout<<num2<<" "<<ss[j]<<endl;
                    if(num2%26==0)
                        num2=num2/26-1;//,f=1;
                    else
                        num2/=26;//,f=0;
 
                }
                //cout<<j<<endl;
                for(;j>=1;j--)
                    if('A'<=ss[j]&&ss[j]<='Z')
                    printf("%c",ss[j]);
                printf("%d\n",num1);
                continue;
            }
        }
        int i=0;
        num1=0,num2=0;
        while('A'<=s[i]&&s[i]<='Z')
            num2=num2*26+s[i++]-'A'+1;
        while('0'<=s[i]&&s[i]<='9')
            num1=num1*10+s[i++]-'0';
        printf("R%dC%d\n",num1,num2);
    }
    return 0;
}

