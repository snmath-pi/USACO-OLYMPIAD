#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 465;
ll dp[N][32][32][32];
const int L = 3;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s; 
	int k; cin >> k;

	int n = (int) s.size();

	vector<int> cnt(L);
	for(int i=0; i<n; i++) {
		cnt[0] += s[i] == 'K';
		cnt[1] += s[i] == 'E';
		cnt[2] += s[i] == 'Y';
	}

	vector<vector<int>> pref(n, vector<int>(L, 0));
	vector<vector<int>> pos(L);
	for(int i=0; i<n; i++) {
		pref[i][0] += s[i]=='K', pref[i][1] += s[i]=='E', pref[i][2] == 'Y';
		if(i) {
			pref[i][0] += pref[i-1][0];
			pref[i][1] += pref[i-1][1];
			pref[i][2] += pref[i-1][2];
		}
		if(s[i]=='K') pos[0].push_back(i);
		if(s[i] == 'E') pos[1].push_back(i);
		if(s[i] == 'Y') pos[2].push_back(i);

	}
	ll ans = 0;
	dp[0][0][0][0] = 1;
	for(int ks=0; ks<=cnt[0]; ks++) {
		for(int es=0; es<=cnt[1]; es++) {
			for(int ys=0; ys<=cnt[2]; ys++) {
				for(int j=0; j<N; j++) {
					if(ks < cnt[0]) {
						int cost = max(0, pref[pos[0][ks]][1] - es) + 
							max(0, pref[pos[0][ks]][2] - ys);
						if(j + cost < N) {
							dp[j+cost][ks+1][es][ys] += dp[j][ks][es][ys];
						}
					}

					if(es < cnt[1]) {
						int cost = max(0, pref[pos[1][es]][0]-ks) + 
							max(0, pref[pos[1][es]][2] - ys);
						if(j + cost < N) {
							dp[j+cost][ks][es+1][ys] += dp[j][ks][es][ys];
						}
					}
					if(ys < cnt[2]) {
						int cost = max(0, pref[pos[2][ys]][0]-ks) +
							max(0, pref[pos[2][ys]][1]-es);
						if(cost + j < N) {
							dp[j+cost][ks][es][ys+1] += dp[j][ks][es][ys];
						}
					}
					
					if(ks==cnt[0] && es==cnt[1] && ys==cnt[2] && j<=k) {
						ans += dp[j][ks][es][ys];
					}
				}
			}
		}
	}
	cout << ans << '\n';
}
