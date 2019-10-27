#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
using namespace std;
#define CASE(c, num) case c: cnt[num] ++; break;
class poker{
public:
    int cnt[14];
    poker(string s){
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
};
////////////////////////// calc rank//////////////////
int straight(poker p){
    if(p[10] && p[1] && p[11] && p[12] && p[13]) // Poyal Straight
        return INT_MAX;
    for(int i = 13; i >= 5; i --){
        bool check = true;
        for(int j = 0; j < 5; j ++)
            if(p[i - j] == 0)
                check = false;
        if(check)
            return i;
    }
    return NULL;
}
int four_of_a_kind(poker p){
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 1)
            return i;
    return NULL;
}
int full_house(poker p){
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 2)
            return i;
    return NULL;
}
int three_of_a_kind(poker p){
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 3)
            return i;
    return NULL;
}
int two_pairs(poker p){
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 1)
            return i;
    return NULL;
}
int pairs(poker p){
    for(int i = 1; i <= 13; i ++)
        if(p[i] == 2)
            return i;
    return NULL;
}
int hight_card(poker p){
    int ans = 0;
    for(int i = 1; i <= 13; i ++)
        if(p[i])
            ans += i;
    return ans;
}
int getval(poker p){
    int ans = 0;
    ans = max(ans, straight(p));
    ans = max(ans, hight_card(p));
    int max_same_card = 0;
    for(int i = 1; i <= 13; i ++){
        max_same_card = max(max_same_card, p[i]);
    }
    switch (max_same_card) {
        case 4: ans = max(ans, four_of_a_kind(p)); break;
        case 3: ans = max(ans, max(full_house(p), three_of_a_kind(p))); break;
        case 2: ans = max(ans, max(two_pairs(p), pairs(p))); break;
        default: ;
    }
    return ans;
}
struct Note{
    string name;
    int rank;
};
bool operator<(Note a, Note b){
    if(a.rank != b.rank) return (a.rank > b.rank);
    return (a.name < b.name);
}
Note nt[100001];
int main(){
    /*
    int n;
    while(cin>>n){
        string name, card;
        for(int i = 0; i < n; i ++){
            cin>>name>>card;
            nt[i].name = name;
            nt[i].rank = getval(poker(card));
        }
        sort(nt, nt + n);
        for(int i = 0; i < n; i ++)
            cout<<nt[i].name<<endl;
    }*/
    string s;
    while(cin>>s){
        cout<<s<<": "<<getval(poker(s))<<endl;
    }
    return 0;
}
