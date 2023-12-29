#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 16;
double value[1 << N], dp[1 << N][N][2];
pair<pair<int, int>, pair<int, int>> cor[N];
double dist(pair<int, int> &p, pair<int, int> &q) {
	int val = (p.fi-q.fi)*(p.fi-q.fi) + (p.se-q.se)*(p.se-q.se);
	return (double)sqrt((double)val);
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n; cin >> n;

	for(int i=0; i<n; i++) {
		cin >> cor[i].fi.fi >> cor[i].fi.se >> cor[i].se.fi >> cor[i].se.se;
	}
	for(int i=0; i<(1 << n); i++) {
		for(int j=0; j<N; j++) {
			dp[i][j][0] = dp[i][j][0] = 2e9;
		}
	}
	for(int i=0; i<N; i++) {
		dp[0][i][0] = dp[0][i][1] = 0.0;
	}
	for(int S = 1; S < (1 << n); S++) {
		for(int i=0; i<n; i++) {
			if(S & (1 << i)) {
				for(int j=0; j<n; j++) {
					if(j==i)continue;

					dp[S][i][0] = min(dp[S][i][0], 
							min(dp[S ^ (1 << i)][j][0] + 
							   dist(cor[j].fi, cor[i].fi), dp[S ^ (1 << i)][j][1]
						   + dist(cor[j].se, cor[i].fi)));
			 		
					dp[S][i][1] = min(dp[S][i][1], 
						min(dp[S ^ (1 << i)][j][0] + 
						dist(cor[j].fi, cor[i].se), dp[S ^ (1 << i)][j][1] + 
							dist(cor[j].se, cor[i].se)));		
				}
			}
		}
	}


	cout << min(dp[(1 << n)-1][0], dp[(1 << n)-1][1]) << '\n';
}
