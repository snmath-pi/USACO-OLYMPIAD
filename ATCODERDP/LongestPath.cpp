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
 
int t, n, m;
vector<vi> adj(100010);
bool vis[100010];
ll dp[100010];

void dfs(int vertex) {
    dp[vertex] = 0;
    vis[vertex] = 1;
    for(int child: adj[vertex]) {
        if(!vis[child]) dfs(child);
        dp[vertex] = max(dp[vertex], dp[child] + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    repn(i, n) {
        if(!vis[i]) dfs(i);
    }
    cout << *max_element(dp, dp + 100010);


}
