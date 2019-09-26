#include <bits/stdc++.h>
using namespace std;
int m, n, q;
int ans;
int book[1000 + 10];
priority_queue<int, vector<int>, less<int>> que;
vector<int> vec;
void judge(int sum){
    priority_queue<int, vector<int>, less<int>> tmp_que = que;
    while(tmp_que.size()){
        int temp = tmp_que.top();
        if(sum < temp){
            ans += 1;
        }else{
            sum -= temp;
        }
        tmp_que.pop();
    }
    vec.emplace_back(ans);
}
int main(){
    cin>>q;
    while(q --){
        while(!que.empty())
            que.pop();
        vec.clear();
        memset(book, 0, sizeof(book));
        cin>>m>>n;
        for(int i = 0; i < m; i ++){
            cin>>book[i];
        }
        for(int i = 0; i < m; i ++){
            ans = 0;
            judge(n - book[i]);
            que.emplace(book[i]);
        }
        int x = vec.size();
        for(int i = 0; i < x; i ++){
            if(i == 0)
                cout<<vec[0];
            else
                cout<<" "<<vec[i];
        }
        cout<<endl;
    }
    return 0;
}


