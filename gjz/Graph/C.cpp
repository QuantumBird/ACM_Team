#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double r[1000][1000];
char s[1000][1000];
int n,m;
int zhuan(char buf[]){
    int i;
    for(i=0; i<m; i++)
        if(strcmp(buf,s[i])==0)
            return i;
    return 0;
}
void Input(){
    char buf1[1000],buf2[1000];
    double rate;
    for(int i=0; i<n; i++){
        scanf("%s",s[i]);
    }
    memset(r,0,sizeof(r));
    for(int i=0; i<n; i++){
        r[i][i] = 1;
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%s %lf %s",buf1,&rate,buf2);
        r[zhuan(buf1)][zhuan(buf2)] = rate;
    }
}
int Floyd(){
    int i,j,k;
    for(  k = 0; k < n; k ++)
        for(  i = 0; i < n; i ++)
            for( j = 0; j < n; j ++)
                if( r[i][j] < r[i][k] * r[k][j])
                    r[i][j] = r[i][k] * r[k][j];
    for( i = 0; i < n; i ++)
        if( r[i][i] > 1)
            return 1;
    return 0;
}
int main(){
    int cas = 0;
    while( scanf( "%d", &n), n){
        Input();
        printf( "Case %d: ", ++ cas);
        int ok = Floyd();
        if(ok) 
        printf( "Yes\n");
        else 
        printf( "No\n");
    }
    return 0;
}
