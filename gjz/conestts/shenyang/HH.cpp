#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
using namespace std;
#define CASE(c, num) case c: cnt[num] ++; break;
struct Poker{
    int cnt[14];
    Poker(){
        memset(cnt, 0, sizeof(cnt));
    }
    void init(string s){
        memset(cnt, 0, sizeof(cnt));
        stringstream ss(s);
        char c;
        while(ss>>c){
            switch(c){
                CASE('A', 1);
                CASE('2', 2);
                CASE('3', 3);
                CASE('4', 4);
                CASE('5', 5);
                CASE('6', 6);
                CASE('7', 7);
                CASE('8', 8);
                CASE('9', 9);
                case '1': ss>>c; cnt[10] ++; break;
                CASE('J', 11);
                CASE('Q', 12);
                CASE('K', 13);
            }
        }
    }
    int operator[](int idx){
        return cnt[idx];
    }
    // just for test
    void display(){
        for(int i = 1; i <= 13; i ++)
            printf("%4d ", i);
        for(int i = 1; i <= 13; i ++)
            printf("%4d ", cnt[i]);
    }
};
istream & operator>>(istream & in, Poker & p){
    string s;
    in>>s;
    p.init(s);
    return in;
}
int getval(Poker p){
    if(p[10] && p[1] && p[11] && p[12] && p[13]) // Poyal Straight
        return INT_MAX;
    // Straight
    for(int i = 13; i >= 5; i --){
       bool check = true;
       for(int j = 0; j < 5; j ++)
           if(p[i - j] == 0)
               check = false;
       if(check)
           return i;
    }
    // Four of a Kind
    int max_same_card = 0;
    for(int i = 1; i <= 13; i ++)
        max_same_card = max(p[i], max_same_card);
    if(max_same_card == 4){
        for(int i = 1; i <= 13; i ++){
            if(p[i] > 0 && p[i] != 4)
                return i;
        }
    }
    // Full House
    if(max_same_card == 3){
        for(int i = 1; i <= 13; i ++){
            if(p[i] == 2)
                return i;
        }
    }
    // Three of a Kind
    if(max_same_card == 3){
        for(int i = 1; i <= 13; i ++){
            if(p[i] == 3)
                return i;
        }
    }
    // Two Pairs
    int pair_cnt = 0;
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 2)
            pair_cnt ++;

    if(max_same_card == 2 && pair_cnt == 2){
        for(int i = 1; i <= 13; i ++)
            if(p[i] == 1)
                return i;
    }
    // Pair
    if(max_same_card == 2 && pair_cnt == 1){
        for(int i = 1; i <= 13; i ++)
            if(p[i] == 2)
                return i;
    }
    // High Card
    if(max_same_card == 1){
        int ans = 0;
        for(int i = 1; i <= 13; i ++){
            if(p[i])
                ans += i;
        }
        return ans;
    }
    return -1;
}
struct Note{
    string name;
    int rank;
    Note(){}
};
bool operator<(Note a, Note b){
    if(a.rank != b.rank) return a.rank > b.rank;
    return a.name < b.name;
}
istream & operator>>(istream & in, Note & n){
    in>>n.name;
    Poker p;
    in>>p;
    n.rank = getval(p);
    return in;
}
Note nt[100001];
int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i < n; i ++)
            cin>>nt[i];
    }
    sort(nt, nt + n);
    for(int i = 0; i < n; i ++){
        cout<<nt[i].name<<endl;
    }
    return 0;
}
