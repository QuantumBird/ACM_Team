#include<bits/stdc++.h>
using namespace std;
int m,n,tmp;

char tmpa[200000+10];
char tmpb[200000+10];
int flag,ans;

char check(int i){
    if(tmpa[i]>='3' && tmpb[i]>='3')
    return '2';
    if(tmpa[i]<='2' && tmpb[i]<='2')
    return '1';
    if(tmpa[i]<='2' && tmpb[i]>='3')
    return '3';
    if(tmpa[i]>='3' && tmpb[i]<='2')
    return '4';
}

int main(){
    scanf("%d",&m);
    while(m--){
        ans = 0;
        flag = 1;
        scanf("%d",&n);
        scanf("%s %s",tmpa,tmpb);
        for(int i=0;i<n;++i){
            tmpa[i] = check(i);
        }
        if(tmpa[0]=='2') flag = -flag;
        else if(tmpa[0]=='4'){
            printf("NO\n");
            continue;
        }
        for(int i=1;i<n;++i){
            if(tmpa[i]=='1' && i==n-1 && flag==1){
                printf("NO\n");
                ans = 1;
                break;
            }else if(tmpa[i]=='2'){
                flag = -flag;
            }else if(tmpa[i]=='3'){
                if(flag==-1){
                    printf("NO\n");
                    ans = 1;
                    break;
                }
            }else if(tmpa[i]=='4'){
                if(flag==1){
                    printf("NO\n");
                    ans = 1;
                    break;                   
                }
            }
        }
        if(flag==1 && !ans){
            printf("NO\n");
        }else if(!ans) printf("YES\n");
    }
    return 0;
}