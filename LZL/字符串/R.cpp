#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;

vector<string>vec;
string str;
int tree[1010][23];
int num[1010];
int tot,root;

int insert(string &str)
{
    root=0;
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        int a=str[i]-'a';
        if(!tree[root][a])
        tree[root][a]=++tot;
        num[tree[root][a]]++;
        root=tree[root][a];
    }
}

int query(string &str)
{
    root=0;
    cout << str << " ";
    int len=str.size();
    for(int i=0;i<len;i++)
    {
        int a=str[i]-'a';
        if(num[tree[root][a]]==1)
        {
            printf("%c",str[i]);
            return 0;
        }
        root=tree[root][a];
        printf("%c",str[i]);
    }
}

int main()
{
    while(cin >> str)
    {
        vec.push_back(str);
        insert(str);
    }
    int x=vec.size();
    for(int i=0;i<x;i++)
    {
        query(vec[i]);
        putchar('\n');
    }
    return 0;
}