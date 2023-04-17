#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
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

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // bowling problem: given n pins with value 
    // you can hit one pin individually value = vi or hit two pins then value = vi * vi+1
    // maximize final value
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl dp(n+1, 0);

    per(i, n) {
        dp[i] = max(dp[i+1], dp[i+1] + a[i]);
        if(i < n-1) dp[i] = max(dp[i], dp[i+2] + a[i] * 1ll * a[i+1]);
    }

    cout << dp[0] << '\n';
}
