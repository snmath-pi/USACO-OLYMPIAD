#include<bits/stdc++.h>
using namespace std;
// INSPIRED BY ERRICHTO
// what is the min weight needed to form a certain value
// dp(j) -> min weight needed to form a value i

int main() {
	int64_t n, w;
	cin >> n >> w;
	vector<int64_t> val(n), weight(n);
	int64_t sum = 0;
	for(int i=0; i<n; i++) {
		cin >> weight[i] >> val[i];
		sum += val[i];
	}
	vector<long long> dp(sum+1, 1e18);
	dp[0] = 0;
	for(int i=0; i<n; i++) {
		for(int vv = sum; vv >= 0; vv--) {
			if(vv + val[i] <= sum) dp[vv + val[i]] = min(dp[vv + val[i]], dp[vv] + weight[i]);
		}
	}
	long long ans = -1e9;
	for(int i=0; i<=sum; i++) {
		if(dp[i] <= w) {
			ans = max(ans, (long long)i);
		}
	}
	cout << ans << '\n';


}
