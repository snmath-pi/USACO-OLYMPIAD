#include<bits/stdc++.h>
using namespace std;

struct state{
	int rides, last;
};

const int N = 20;
state dp[1 << N];
int weights[N];
int main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int n, X;
	cin >> n >> X;
	
	for(int i=0; i<n; i++) {
		cin >> weights[i];
	}

	dp[0].rides = 1; dp[0].last = 0; // empty group considered as an entity

	for(int S=1; S<(1 << n); S++) {
		// intial value: n + 1 rides are needed
		dp[S].rides = n + 1, dp[S].last = 0;

		for(int i=0; i < n; i++) {
			if(S & (1 << i)) {
				state T = dp[S ^ (1 << i)];
				if(T.last + weights[i] <= X) {
					T.last += weights[i]; 
					// add i guy to the existing ride
				} else {
					// if his weight makes the weight exceed LIMIT
					// reserve a new ride for i guy
					T.rides++;
					T.last = weights[i];
				}
				if(dp[S].rides > T.rides) {
					dp[S] = T;
				} else if(dp[S].rides == T.rides) {
					dp[S].last = min(dp[S].last, T.last);
				}
			}
		}
	}

	cout << dp[(1 << n)-1].rides << '\n';

}

