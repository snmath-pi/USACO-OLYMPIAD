#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>> 
#define vi vector<int>
#define vb vector<bool> 
#define pb push_back
int main() {
	int n, m, v;
	cin >> n >> m >> v;
	v--;
	vvi g(n);
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		if(u!=v) g[--u].pb(--v);
		
	}

	vi dis(n, -1);
	queue<int> q;
	q.push(v);
	vb vis(n, 0);
	vis[v] = 1;
	dis[v] = 0;
	while(!q.empty()) {
		int s = q.front(); q.pop();
		for(auto u: g[s]) {
			if(vis[u]) continue;
			vis[u] = 1;
			dis[u] = dis[s] + 1;
			q.push(u);
		}
	}

	for(int i=0; i<n; i++) {
		cout << dis[i] << ' ';
	}
	
}
