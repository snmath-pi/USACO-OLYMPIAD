#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e2 + 5;
long long dp[M][N];
vector<int> weight(M), value(M);
int main() {
	int n, w;
	cin >> n >> w;
	for(int i=1; i<=n; i++) {
		cin >> weight[i] >> value[i];
	}
	for(int j=1; j<=w; j++) {
		for(int i=1; i<=n; i++) {
			if(weight[i] <= j) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}
	cout << dp[n][w];
}
