#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
int t, n;
ll dp[1010][1010];
const int M  = 1000000007;
int h, w;
char a[1010][1010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = (a[0][0] != '#')?1:0;
	rep(i, h) {
		rep(j, w) {
			if(a[i][j] !='#') {
				if(i > 0) dp[i][j] += dp[i-1][j];
				dp[i][j] %= M;
				if(j>0) dp[i][j] += dp[i][j-1];
				dp[i][j] %= M;
			} else dp[i][j] = 0;
		}
	}

	cout << dp[h-1][w-1] % M;

}
