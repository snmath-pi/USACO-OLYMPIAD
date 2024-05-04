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
#define vc vector<char>
#define vs vector<string>
#define vvb vector<vb>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvc vector<vc>
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
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back() 
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define ld long double
#define nl '\n'
#define sp ' '
#define fi first
#define se second
#define mpr make_pair
#define nout(n) cout << n << '\n'
#define sout(n) cout << n << ' '

using namespace std;
/* ありがとう、神様、あなたはとても素晴らしく 、とても優しいです！*/
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

// customHash working with UMP
struct hsh {
    size_t operator()(const pair<ll,ll> &p) const {
        return p.first * 239 + p.second; //you could change 239 to 1e9+1
    }
};

template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
template <typename T, typename V> 
T rangeBitwiseAnd(T left, V right) {
    T res = 0;
    int cnt = 0; for(; left >= (1ll<<cnt); cnt++){}
    if(1ll<<cnt <= right) return 0;
    if(left==right) return left;
    
    res += 1ll<<(--cnt);
    left -= 1ll<<(cnt); right -= 1ll<<cnt;
    return res + rangeBitwiseAnd(left, right);
}

int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
int kx[]={1, 1, -1, -1, 2, 2, -2, -2};
int ky[]={2, -2, 2, -2, 1, -1, 1, -1};
set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

bool chkpalin(string s) {
    rep(i, sz(s)/2) {
        if(s[i] != s[sz(s)-i-1]) return false;
    }
    return true;
}
map<char, vector<char>> phone_keypad{
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};
vi generate_primes(int N) {
    vi x(N+10, 1), primes;
    x[0] = x[1] = 0;
    rng(i, 2, N + 5) {
        if(!x[i]) continue;
        for(int j=i+i; j<N+5; j+=i) x[j] = 0;
    }
    rep(i, N+10) {
        if(x[i]) primes.pb(i);
    }
    return primes;
}

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

ll n, k, m, q;
//const ll mod = 998244353;
const ll mod = 1000000007;
struct segtree {
	vector<long long> tree;
	int n;
	segtree(int x) {
		for(n = 1; n < x; n *= 2) {}
		tree.resize(2*n);
	}	

	ll fun(ll x, ll y) {
		return x + y;
	}
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx-lx==1) {
			if(lx < (int) a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int m = lx + rx >> 1;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		tree[x] = fun(tree[2*x+1], tree[2*x+2]);
	}
	void build(vector<int> &a) {
		build(a, 0, 0, n);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) tree[x] = v;
		else {
			int m = lx + rx >> 1;
			if(i < m) {
				set(i, v, 2*x + 1, lx, m);
			} else {
				set(i, v, 2*x + 2, m, rx);
			}
			tree[x] = fun(tree[2*x+1], tree[2*x+2]);
		}
	}
	void set(int i, int v) {
		set(i, v, 0, 0, n);
	}
	long long sum(int x, int l, int r, int lx, int rx) {
		if(lx >= r || rx <= l) return 0;
		if(lx>=l && rx<=r) return tree[x];
		int m = lx + rx >> 1;
		return sum(2*x+1, l, r, lx, m) + sum(2*x+2, l, r, m, rx);
	}
	long long sum(int x, int l, int r) {
		return sum(x, l, r, 0, n);
	}
	int min_e(int x, int l, int r, int lx, int rx) {
		if(lx >= r || rx <= l) return 2e9;
		if(lx>=l && rx<=r) return tree[x];
		int m = lx + rx >> 1;
		return min(min_e(2*x+1, l, r, lx,m), min_e(2*x+2, l, r, m, rx));
	}
   	int min_e(int l, int r) {
		return min_e(0, l, r, 0, n);
	}
};



int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    
    cin >> n >> q;
    vl a(n);
    rep(i, n) cin >> a[i];

    vvi g(n);
    rep(i, n-1) {
    	int u, v; cin >> u >> v;
    	g[--u].pb(--v); g[v].pb(u);
    }
    vi sub(n), tim(n), id(n);
    int t = 0;
    auto dfs = [&](int i, int p, auto &&dfs)->void {
    	sub[i] = 1;
    	id[t] = i;
    	tim[i] = t++;

    	for(const auto &x: g[i]) {
    		if(x != p) {
    			dfs(x, i, dfs);
    			sub[i] += sub[x];
    		}
    	}
    }; 
    dfs(0, -1, dfs);
    
    vi b(n);
    rep(i, n) {
    	b[i] = a[id[i]];
    }
    segtree st(n);
    st.build(b);
    rep(i, q) {
    	int type, s, x; cin >> type;
    	debug(type)
    	if(type == 1) {
    		cin >> s >> x;--s;
    		st.set(tim[s], x);
    	} else {
    		cin >> s;--s;
    		cout << st.sum(0,tim[s], tim[s] + sub[s]) << nl; 
    	}
    }
}

