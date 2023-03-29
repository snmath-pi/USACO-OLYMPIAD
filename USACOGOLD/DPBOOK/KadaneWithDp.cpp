/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
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
    int a[n];
    rep(i, n) cin >> a[i];
    int dp[n];
    dp[0] = a[0]; // if we are allowed to select no element at all dp[0] = max(0, a[0]);
    rng(i, 1, n) {
        dp[i] = max(dp[i-1]+a[i], a[i]);
    }
    cout << *max_element(dp, dp+n);

}
