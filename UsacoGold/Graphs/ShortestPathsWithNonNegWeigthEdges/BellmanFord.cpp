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
void solve() {
    cin >> n >> m >> source;
    source--;
    vector<pair<pii, int>> g(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g.pb(mpr(mpr(--u,--v), w));
        g.pb(mpr(mpr(v, u), w));
    }
    const int inf = 1e9;
    vi dis(n, inf); dis[source] = 0; // its distance from itself is taken = 0;
    rep(i, n-1) {
        for(auto x: g) {
            chkmin(dis[x.fi.se], dis[x.fi.fi] + x.se);
        }
    }

    for(auto x: dis) cout << x << sp; cout << nl;
    // if the graph has negative edge cycles 
    // do another iteration if any distance decrease that indicates there is a nec
    vi dis_cur = dis;
    rep(i, 1) {
        for(auto x: g) {
            chkmin(dis[x.fi.se], dis[x.fi.fi] + x.se);
        }
    }
    rep(i, n) {
        if(dis_cur[i] > dis[i]) {
            cout << "YES THERE IS A NEGATIVE EDGE CYCLE\n";
            return;
        }
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
