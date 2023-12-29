#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long


int findlis(vector<int> &a) {
	vector<int> dp;
	// Li[j] -> minimum element among the first ith elements that is the end of 
	// a lis of legnth j;
	//
	
	for(auto &i: a) {
		int pos = lower_bound(begin(dp), end(dp), i)-begin(dp);
		if(pos == dp.size()) {
			dp.push_back(i);
		} else {
			dp[pos] = i;
		}
	}
	return dp.size();
}
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << findlis(a) << '\n';
}
