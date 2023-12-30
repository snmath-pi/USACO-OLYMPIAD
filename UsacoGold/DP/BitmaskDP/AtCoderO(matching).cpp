#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const int N = 21;
const int mod = 1e9 + 7;
int A[N][N];
ll dp[1 << N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
	dp[0] = 1;
	for(int S = 0; S < (1 << n); S++) {
		for(int i=0; i<n; i++) {
			if(!(S & (1 << i))) {
				if(!A[__builtin_popcount(S)][i]) continue;
				dp[S | (1 << i)] += (dp[S]);
				dp[S | (1 << i)] %= mod;
			}
		}
	}

	cout << dp[(1 << n)-1] << '\n';

}
