#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
vector<int> que;
int book[200000+10];
bool flag[200000+10];
int sum;
int main(){
    cin >> sum;
    for(size_t i = 1; i <= sum; i++){
        cin >> book[i];
    }
    for(size_t i = 1; i <= sum; i++){
        if(!book[i]) vec.push_back(i);
        else flag[book[i]] = true;
    }
    for(size_t i = 1; i <= sum; i++){
        if(!flag[i])  que.push_back(i);
    }
    for(int i = 0; i < vec.size()-1; i++){
        if(vec[i] == que[i] || vec[i+1] == que[i+1]){
            swap(que[i], que[i+1]);
        }
        book[vec[i]] = que[i];
    }
    book[vec[vec.size()-1]] = que[que.size()-1];
    for(size_t i = 1; i <= sum; i++){
        cout << book[i] << " ";
    }
    return 0;
}
