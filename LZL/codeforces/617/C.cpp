#include <bits/stdc++.h>
using namespace std;

int sum,q;
string path;
using pa = std::pair<int,int>;
map<pa, int> stamp; //无序的insert那是错的
map<int,pa> ans; 

void process(int xx, int yy, int vis){
    pa Temp = make_pair(xx,yy);

    auto T = stamp.find(Temp); 
    if(T != stamp.end()){
        ans.insert(make_pair(vis-T->second,make_pair(T->second, vis)));
    }
    stamp.insert(make_pair(std::move(Temp),vis));
}

int main(){
    cin >> q;
    while(q--){
        ans.clear();
        stamp.clear();
        int xx = 0,yy = 0;
        int vis = 0;
        stamp.insert(make_pair(make_pair(0,0),0));
        cin >> sum >> path;
        for(auto x : path){
            ++vis;
            switch (x)
            {
                case 'L':
                    xx-=1;
                    process(xx,yy,vis);
                    break;
                case 'R':
                    xx+=1;
                    process(xx,yy,vis);
                    break;
                case 'U':
                    yy+=1;
                    process(xx,yy,vis);
                    break;
                case 'D':
                    yy-=1;
                    process(xx,yy,vis);
                    break;
            }
        }
        if(!ans.size()) cout << "-1\n";
        else cout << ans.begin()->second.first+1 << " " << ans.begin()->second.second << endl;
    }
    return 0;
}