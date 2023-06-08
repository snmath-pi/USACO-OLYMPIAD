#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vvb vector<vb>
#define vvi vector<vi>
#define vvl vector<vl>
#define si unordered_set<int>
#define sl unordered_set<ll>
#define tsi set<int>
#define tsl set<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define tmii map<int, int>
#define tmll map<ll, ll>
#define mii unordered_map<int, int>
#define mll unordered_map<ll, ll>
#define pqi priority_queue<int>
#define pqig priority_queue<int, vi, greater<int>>
#define pql priority_queue<ll>
#define pqlg priority_queue<ll, vl, greater<ll>>
#define pqpii priority_queue<pii>
#define pqpll priority_queue<pll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define nl '\n'
#define sp ' '
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << sp; use_(x); cerr << nl;
#else
#define debug(x)
#endif

template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};

void yesnoc(bool a) {
    cout << (a? "YES\n": "NO\n");
}
void yesnos(bool a) {
    cout << (a? "Yes\n": "No\n");
}
 
int t, n, m, source;
// n number of vertices in the given graph
// m number of edges in the given graph
// source: distance of all the vertices from this given source
// the graph may have negative weight edges but never negitive weight cycles
// why? If there is such a negative cycle, you can just traverse this cycle over and over, 
// in each iteration making the cost of the path smaller. So you can make certain paths arbitrarily small, or in other words that shortest path is undefined. 
//That automatically means that an undirected graph cannot have any negative weight edges, 
//as such an edge forms already a negative cycle as you can move back and forth along that edge as long as you like.
//This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at the end of the algorithm, 
// the distance from a vertex v to itself is negative.
void solve() {
    cin >> n >> m >> source;
    source--; const int inf = 1e9 + 7;
    vvi dis(n, vi(n, inf));
    rep(i, n) dis[i][i] = 0;
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[--u][--v] = w;
        dis[v][u] = w;
    }
    // use all nodes as intermediate nodes
    rep(intermediate, n) {
        rep(i, n) rep(j, n) {
            chkmin(dis[i][j], dis[i][intermediate] + dis[intermediate][j]);
          /*
          in case of negative weight edges it is better to check
          if(dis[i][j] < inf && dis[j][i] < inf) chkmin(dis[i][j], dis[i][intermediate] + dis[intermediate][j]);
          */
        }
    }
    rep(i, n) {
        rep(j, n) {
            cout << dis[i][j] << sp;
        }cout << nl;
    }
    
/* sample
5 7 1
1 2 5
1 3 3
2 5 2
2 4 3 
4 5 2
1 4 7
3 4 1
*/

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
