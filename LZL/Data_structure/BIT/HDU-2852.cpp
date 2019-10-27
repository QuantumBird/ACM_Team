//区间第K大也可以用树状数组+二分的写法来解决　解决了一类问题
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<cstdio>
using namespace std;

int m,n;
const int maxn = 100000+10;
int flag,tmpa,tmpb,num1,num2;
int low[maxn];

int lowbit(int i){
    return i&-i;
}

int add(int i,int w){
    while(i<maxn){
        low[i] += w;
        i+=lowbit(i);
    }
}

int sum(int i){
    int ans = 0;
    while(i>0){
        ans += low[i];
        i-=lowbit(i);
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    while(cin >> m){
        memset(low,0,sizeof(low));
        while(m--){
            cin >> n;
            switch (n)
            {
                case 0://添加
                    cin >> tmpa;
                    add(tmpa,1);
                    break;
                case 1://删除
                    cin >> tmpa;
                    if(sum(tmpa) - sum(tmpa-1) == 0){
                        cout << "No Elment!\n";
                    }else add(tmpa,-1);
                    break;
                case 2:
                    cin >> tmpa >> tmpb;//比tmpa大的第tmpb个数
                    int left = tmpa;
                    int right = maxn;
                    int mid = 0;
                    num1 = sum(tmpa);
                    while(left <= right){
                        mid = left + (right - left) / 2;
                        num2 = sum(mid);
                        if(num2 - num1 >= tmpb){
                            right = mid - 1;
                        }else{
                            left = mid + 1;
                        }
                    }
                    if(left >= maxn) {
                        cout << "Not Find!\n";
                    }else{
                        cout << left << "\n";
                    }
                    break;
            }
        }
    }
    return 0;
}