#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 2e6;
pair<int, int> A[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	//freopen("pcb.in", "r", stdin);
	//freopen("pcd.out", "w", stdout);
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> A[i].first >> A[i].second;
		A[i].second *= -1;
	}
	sort(A, A+n);

	vector<int> dp;
	for(int i=0; i<n; i++) {
		int pos = lower_bound(begin(dp), end(dp), A[i].second)-begin(dp);
		if(pos == dp.size()) dp.push_back(A[i].second);
		else dp[pos] = A[i].second;
	}

	cout << dp.size() << '\n';
}
