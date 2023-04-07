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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<array<int, 3>> a(n);
    rep(i, n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector<array<int, 3>> dp(n, {0, 0, 0});
    dp[0][0] = a[0][0]; dp[0][1] = a[0][1]; dp[0][2] = a[0][2];
    rng(i, 1, n) {
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);

    }
    
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

}
