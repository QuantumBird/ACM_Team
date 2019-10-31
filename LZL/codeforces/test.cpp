#include<bits/stdc++.h>
using namespace std;

const int maxn = 200000+10;
int m,n,from,to,root;
int in[maxn];
vector<int> G[maxn];
int book[maxn];

bool bfs(int root){
	set<int> se;
	queue<int> que;
	que.push(root);
	int index = 2;
	se.insert(root);
	if(root != book[1]) return false;
	while(!que.empty()){
		int temp = que.front();
		que.pop();
		size_t len = G[temp].size();
		vector<int>aa;
		vector<int>bb;
		for(int i=0;i<len;++i){
			aa.push_back(G[temp][i]);
			bb.push_back(book[index+i]);
		}
		sort(aa.begin(),aa.end());
		sort(bb.begin(),bb.end());
		if(aa == bb){
			for(int i=0;i<len;++i){
				if(se.find(book[index]) != se.end()) return false;
				se.insert(book[index]);
				que.push(book[index++]);	
			}
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	cin >> m;
	set<int>se;
	for(int i=0;i<m-1;++i){
		cin >> from >> to;
		se.insert(from);
		se.insert(to);
		G[from].push_back(to);
		in[to]++;
	}
	for(int i=1;i<=m;++i){
		cin >> book[i];
	}
	if(m==1 && book[1] == 1){
		cout << "Yes\n";
		return 0;
	}
	for(set<int>::iterator T = se.begin();T != se.end();T++){
		if(in[*T] == 0){
			root = *T;
			break;
		}
	}
	if(root != 1){
		cout << "No\n";
		return 0;
	}
	if(bfs(root)){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}
