#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[10001][31];
int tot,size;
int sz,t[300001][26],s[300001];
void insert(char *ch){
    int k,len=strlen(ch),now=0;
    for(int p = 0; p < len; p ++){
    	k = ch[p] - 'a';
    	if(t[now][k] == 0)
            t[now][k] = ++sz;
        now = t[now][k];
        s[now]++;
    }
}
void display(char *ch){
	int now = 0, k, len = strlen(ch);
	for(int p = 0; p < len; p++){
		if(s[now] == 1) break;
		k = ch[p] - 'a';
		printf("%c",ch[p]);
		now = t[now][k];
   }
}
int main(){
    while(scanf("%s",a[++tot])!=EOF)
        insert(a[tot]);
    for(int i=1;i<=tot;i++){
        printf("%s ",a[i]);
        display(a[i]);
        printf("\n");
    }
    return 0;
}