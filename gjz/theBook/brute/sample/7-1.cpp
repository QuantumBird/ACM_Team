#include <iostream>
#include <cstdio>
using namespace std;
bool notSame(int a, int b){
    bool note[10];
    for(int i = 0; i < 10; i ++) note[i] = false;
    if(a < 10000) note[0] = true;
    if(b < 10000) note[0] = true;
    while(a){
        if(note[a % 10]) return false;
        note[a % 10] = true;
        a /= 10;
    }
    while(b){
        if(note[b % 10]) return false;
        note[b % 10] = true;
        b /= 10;
    }
    return true;
}
void display(int n){
    if(n < 10000)
        printf("0%d", n);
    else
        printf("%d", n);
}
void solve(int n){
    bool have_ans = false;
    for(int i = 1234; i <= 98765; i ++){
        int t = i*n;
        if(t > 100000) 
            continue;
        if(notSame(t, i)){
            display(t);
            printf(" / ");
            display(i);
            printf(" = %d\n", n);
            have_ans = true;
        }
    }
    if(! have_ans){
        printf("There are no solutions for %d.\n", n);
    }
    //printf("\n");
}
int main(){
    int n;
    bool change = false;
    while(~scanf("%d", &n), n){
        if(change)
            printf("\n");
        else
            change = true;
        solve(n);
    }
    return 0;
}


