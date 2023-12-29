#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int value[1 << N], dp[1 << N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	
	int n; cin >> n;

	for(int i=0; i<(1 << n); i++) {
		cin >> value[i];
		dp[i] = value[i];
	}	

	for(int k=0; k<n; k++) {
		for (int S=0; S < (1 << n); S++) {
			if(S & (1 << k)) dp[S] += dp[S ^ (1 << k)];
		}
	}

	for(int S=0; S < (1 << n); S++) {
		cout << dp[S] << ' ';
	}
	
		
}
