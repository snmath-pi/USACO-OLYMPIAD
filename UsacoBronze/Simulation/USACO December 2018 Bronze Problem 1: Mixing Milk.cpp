// Saksham Negi
#include <algorithm>
#include <stack>
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
#define nout(n) cout << n << '\n'
#define sout(n) cout << n << ' '


using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << sp; use_(x); cerr << nl;
#else
#define debug(x)
#endif

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    mordered_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int kx[]={1, 1, -1, -1, 2, 2, -2, -2};
int ky[]={2, -2, 2, -2, 1, -1, 1, -1};

void yesnoc(bool a) {
    cout << (a? "YES\n": "NO\n");
}
void yesnos(bool a) {
    cout << (a? "Yes\n": "No\n");
}

void use_(ll W) {cerr << W;}
void use_(ld W) {cerr << W;}
void use_(char W) {cerr << W;}
void use_(string W) {cerr << W;}
void use_(int W) {cerr << W;}
void use_(double W) {cerr << W;}
#define trace1(x)                cerr << #x << ": " << (x) << nl;
#define trace2(x, y)             cerr << #x << ": " << (x) << " | " << #y << ": " << (y) << nl;
#define trace3(x, y, z)          cerr << #x << ": " << (x) << " | " << #y << ": " << (y) << " | " << #z << ": " << (z) << nl;
#define trace4(a, b, c, d)       cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << nl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << " | " << #e << ": " << (e) << nl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << (a) << " | " << #b << ": " << (b) << " | " << #c << ": " << (c) << " | " << #d << ": " << (d) << " | " << #e << ": " << (e) << " | " << #f << ": " << (f) << nl;


template<typename T, typename V> void use_(pair<T, V> p) {
    cerr << "["; use_(p.fi); cerr << ','; use_(p.se); cerr << ']';
}
template<typename T> void use_(vector<T> a) {
    cerr << '['; for(T i: a) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T> void use_(set<T> a) {
    cerr << '['; for(T i: a) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T> void use_(multiset<T> ms) {
    cerr << '['; for(T i: ms) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T, typename V> void use_(map<T, V> mp) {
    cerr << '[';  for(auto x: mp) { use_(x.fi); cerr << ','; 
        use_(x.se); cerr << sp;
    } cerr << ']'; cerr << nl;
}

int n, k, m, q;
const int mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    vi a(3),c(3);
    rep(i, 3) {
        cin >> c[i] >> a[i];
    }
    debug(a) debug(c)
    int i=0;
    rep(j,100) {
        int amt=min(a[i%3],c[(i+1)%3]-a[(i+1)%3]);
        a[i%3]-=amt;a[(i+1)%3]+=amt;
        i++;
        debug(a)
    }
    rep(i, 3) cout << a[i] << nl;

}

