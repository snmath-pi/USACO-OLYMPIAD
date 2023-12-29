#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 2e6;
int A[N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	//freopen("pcb.in", "r", stdin);
	//freopen("pcd.out", "w", stdout);
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> A[i];
	}

	vector<int> dp(n+1, 2e9);
	dp[0] = -2e9;

	for(int i=0; i<n; i++) {
		int pos = upper_bound(begin(dp), end(dp), A[i]) - begin(dp);
		if(dp[pos-1] <= A[i] && A[i] <= dp[pos]) {
			dp[pos] = A[i];
		}
	}

	int res = 0;
	for(int i=0; i<=n; i++) {
		if(dp[i]!=2e9) res = i;
	}

	cout << res << '\n';
}
