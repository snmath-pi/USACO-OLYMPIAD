#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 2e6;
int A[N], B[N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	//freopen("pcb.in", "r", stdin);
	//freopen("pcd.out", "w", stdout);
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> A[i];
		B[--A[i]] = i;
	}
	
	for(int i=0; i<n; i++) {
		int x; cin >> x;
		A[i] = B[--x];
	}

	vector<int> dp;
	for(int i=0; i<n; i++) {
		int pos = lower_bound(begin(dp), end(dp), A[i]) - begin(dp);
		if(pos == dp.size()) dp.push_back(A[i]);
		else dp[pos] = A[i];
	}

	cout << dp.size() << '\n';
}
