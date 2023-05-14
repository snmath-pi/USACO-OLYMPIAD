#include <bits/stdc++.h>

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
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define nl '\n'
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

template<typename T> void chkmn(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmx(T& x, T y) {if(x < y) x = y;}

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;
const int N = 1e3 + 5;
string grid[N];
bool vis[N][N];
bool good(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < n );
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void floodfill(int i, int j, int &a, int &b) {
	stack<pair<int, int>> f;
	f.push({i, j});
	int w = -1, x = 1e9, y = -1, z  = 1e9;
	while(!f.empty()) {
		int r = f.top().fi;
		int c = f.top().se;
		f.pop();
		
		if(!good(r, c)) {
			b++;
			continue;
		}
		if(vis[r][c]) continue;
		if(grid[r][c] == '.') {
			b++;
			continue;
		}
		vis[r][c] = 1;
		a++; // since area is basically no of #
		// perimeter is a bit trick;
		w = max(w, r);
		x = min(x, r);
		y = max(y, c);
		z = min(z, c);
		for(int i=0; i<4; i++) {
			f.push({r + dx[i], c + dy[i]});
		}

	}
	
	// cout << w << ' '<< x << ' ' << y << ' ' << z << ' '<< b << '\n';
}
int components = 0;
void setIO(string s) { 
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setIO("perimeter");
    cin >> n;
    rep(i, n) {
    	cin >> grid[i];
    }
    // how is the perimeter 22?
    map<int, int> mp;
    rep(i, n) {
    	rep(j, n) {
    		if(grid[i][j] == '#' && !vis[i][j]) {
    			int area = 0, perimeter = 0;
    			floodfill(i, j, area, perimeter);
    			// cout << area << perimeter << ' ';
    			if(mp.count(area)) {
    				if(mp[area] > perimeter) {
    					mp[area] = perimeter;
    				} 
    			} else mp[area] = perimeter;
    		}
    	}
    }
    int a = -1, b = -1;
    for(auto x: mp) {
    	if(x.fi > a) {
    		a = x.fi, b = x.se;
    	}
    }
    cout << a << ' ' << b;

}
