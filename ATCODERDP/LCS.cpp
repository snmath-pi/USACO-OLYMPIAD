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
string a, b;
int dp[3010][3010];

string f(int i, int j) {
    if(i == 0 or j == 0) {
        return "";
    }
    if(a[i-1] == b[j-1]) {
        return f(i-1, j-1) + a[i-1];
    }
    if(dp[i][j-1] > dp[i-1][j]) {
        return f(i, j-1);
    }
    return f(i-1, j);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    int n = sz(a), m = sz(b);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; // first property
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // second property
            }
        }
    }
    string s = f(n, m);
    cout << s;

}
