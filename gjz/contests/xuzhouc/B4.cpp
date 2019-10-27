#include <iostream>
using namespace std;
const int maxn = 1e9 + 1;
typedef struct node{
    int id, lch, rch;
    node(){
        lch = rch = NULL;
    }
    node(int n, int l, int r):
    id(n), lch(l), rch(r){}
} node;
node tre[maxn];
int node_num;
int find_last(int num, int idn){
    if(tre[idn].id == idn) return NULL;
    if(tre[idn].id > num){
        int nxt = tre[idn].lch;
        if(nxt == NULL)
            return idn;
        return find_last(num, nxt);
    }else{
        int nxt = tre[idn].rch;
        if(nxt == NULL)
            return idn;
        return find_last(num, rch);
    }
}
void insert_node(int num){
    if(node_num == 0){
        tre[node_num].id = num;
        tre[node_num].lch = NULL;
        tre[node_num].rch = NULL;
        node_num ++;
        return;
    }
    int tmp = find_last(num, 0);
    if(tmp == NULL) return;
    if(tre[tmp].id > num){
        tre[tmp].lch = node_num + 1;
        node_num ++;
        tre[node_num].id = num;
        tre[node_num].lch = NULL;
        tre[node_num].rch = NULL;
    }else{
        tre[tmp].rch = node_num + 1;
        node_num ++;
        tre[node_num].id = num;
        tre[node_num].lch = NULL;
        tre[node_num].rch = NULL;
    }
}
int query