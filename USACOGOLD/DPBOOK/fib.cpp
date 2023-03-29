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

int memo[60];
int fib(int x) {
    if(memo[x] != -1) return memo[x];
    if(x <= 2) return 1;
    return memo[x] = fib(x-1) + fib(x-2);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<=n; i++) {
        memo[i] = -1;
    }

    int ans = fib(n);
    cout << ans;
}
