#include<cstdio>
#include<cstdlib>
using namespace std;
 
int a[110];
int n;
int min_ans;
int max_ans;
int sum(int c,int b){
    int total=0;
    for (int i=c; i<c+b; i++)
        total=total+a[i%n];
    return total;
}
void Merge(){
    int min_dp[110][110];
    int max_dp[110][110];
    for(int i=0; i<n; i++){
        min_dp[i][1]=0;
        max_dp[i][1]=0;
    }
    for(int i=2; i<=n; i++){
        int temp1,temp2;
        for(int j=0; j<n; j++){
            min_dp[j][i]=min_dp[j][1]+min_dp[(j+1)%n][i-1];
            max_dp[j][i]=max_dp[j][1]+max_dp[(j+1)%n][i-1];
            for(int k=2; k<i; k++){
                temp1=min_dp[j][k]+min_dp[(j+k)%n][i-k];
                if(temp1 < min_dp[j][i])
                    min_dp[j][i] = temp1;
                temp2=max_dp[j][k]+max_dp[(j+k)%n][i-k];
                if(temp2 > max_dp[j][i])
                    max_dp[j][i] = temp2;
            }
            int sums=sum(j,i);
            min_dp[j][i]+=sums;
            max_dp[j][i]+=sums;
        }
    }
    min_ans=0x3f3f3f3f;
    max_ans=-1;
    for (int i=0; i<n; i++){
        if (min_ans>min_dp[i][n])
            min_ans=min_dp[i][n];
        if (max_ans<max_dp[i][n])
            max_ans=max_dp[i][n];
    }
    return;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        Merge();
        printf("%d %d\n",min_ans,max_ans);
    }
    return 0;
}

