#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7+10;
const int MAX = 6000+10;
using pa = pair<int,int>;
vector<pa>G[maxn];
list<pa>vec[MAX];
int T,m,n,flag,w,len,x,y,number;
int lastans;
inline int xx(int x){
    return (((x+lastans)%6000)+1);
}

inline int yy(int y){
    return (((y+lastans)%6000)+1);
}

void init(){
    for(int i=0;i<=6000;++i){
        for(int j=0;j<=6000;++j){
            if(i*i+j*j <= 1e7){
                G[i*i+j*j].push_back(make_pair(i,j));
            }
        }
    }
}

int main(){
	cin >> T;
	init();
	while(T--){
        lastans = 0;
        for(int i=0;i<MAX-1;++i) vec[i].clear();
		cin >> m >> n;
		for(int i=0;i<m;++i){
			cin >> x >> y >> w;
			vec[x].push_back(make_pair(y,w));
		}
        cout << "Case #" << ++number << ":\n";
        int dd = n;
		for(int i=0;i<dd;++i){
			cin >> flag >> m >> n;
            m = xx(m);
            n = yy(n);
			switch(flag){
				case 1:
					cin >> w;
					vec[m].push_back((make_pair(n,w)));
					break;
				case 2:
					{
						list<pa>::iterator TT;
						for(auto temp = vec[m].begin();temp!=vec[m].end();temp++){
							if(temp->first == n){
								TT = temp;
								break;
							}
						}
                        //cout << "erase (" << m << "," << TT->first << "," <<TT->second <<")\n";
						vec[m].erase(TT);
						break;
					}
				case 3:
					{
                        set<pa>se;
						cin >> len >> w;
						for(auto x : G[len]){
							if(m-x.first >= 1){
								for(auto &T : vec[m-x.first]){
                                    pa temp = make_pair(m-x.first,T.first);
									if(abs(T.first-n) == x.second && se.find(temp) == se.end()){
                                        se.emplace(temp);
										T.second+=w;
									}
								}
							}
							if(m+x.first<=6000){
								for(auto &T : vec[m+x.first]){
                                    pa temp = make_pair(m+x.first,T.first);
									if(abs(T.first-n) == x.second && se.find(temp) == se.end()){
                                        se.emplace(temp);
										T.second+=w;
									}
								}
							}
						}
					}
					break;
				case 4:
					{
                        set<pa>se;
						int ans = 0;
						cin >> len;
						for(auto x : G[len]){
							if(m-x.first >= 1){
								for(auto &T : vec[m-x.first]){
                                    pa temp = make_pair(m-x.first,T.first);
									if(abs(T.first-n) == x.second && se.find(temp)==se.end()){
                                        se.emplace(temp);
                                        //cout << "ans :";
										//cout << "x: " << m-x.first << " y: " << T.first << "T :" << T.second<< endl;
                                        ans+=T.second;
									}
								}
							}
							if(m+x.first<=6000){
								for(auto &T : vec[m+x.first]){
                                    pa temp = make_pair(m+x.first,T.first);
									if(abs(T.first-n) == x.second && se.find(temp)==se.end()){
                                        se.emplace(temp);
                                        //cout << "ans :";
                                        //cout << "x: " << m+x.first << " y: " << T.first << "T :" << T.second<< endl;
										ans+=T.second;
									}
								}
							}
						}
                        lastans = ans;
						cout << ans << endl;
					break;
					}
			}
		}
	}
}