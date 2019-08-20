#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<string, int> a,b;
string s[1017];
int main()
{
    int x[1017];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i] >> x[i];
        a[s[i]]+=x[i];
    }
    int maxx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[s[i]] > maxx)
            maxx = a[s[i]];
    }
    for(int i = 1; i <= n; i++)
    {
        b[s[i]]+=x[i];
       if((b[s[i]]>=maxx)&&(a[s[i]]>=maxx))
        {
            cout << s[i];
            break;
        }
    }
    return 0;
}

