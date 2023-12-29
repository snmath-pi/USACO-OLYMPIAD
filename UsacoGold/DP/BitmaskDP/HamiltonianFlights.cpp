#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const int N = 20;
vector<int> g[N];
const int mod = 1e9 + 7;
ll dp[1 << N][N]; 
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int u, v; cin >> u >> v;
		g[--v].push_back(--u);
	}
	dp[1][0] = 1;
	for(int S = 2; S < (1 << n); S++) {

		if((S & (1 << 0)) == 0) continue;

		if(S & (1 << (n-1)) && S != (1 << n)-1) continue;
		for(int i = 0; i < n; i++) {

			if(S & (1 << i)) {
				for(auto &j: g[i]) {
					if(S & (1 << j)) {
						dp[S][i] += dp[S ^ (1 << i)][j];
						dp[S][i] %= mod;
					}
				}
			}
		}
	}
	cout << dp[(1 << n)-1][n-1];



}	
