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
 
void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;
 
 
 
struct dsu_cpbook {
	vi link, size; int mx = 1;
	dsu_cpbook(int n) {
		
		link.resize(n);
		size.assign(n, 1);
		rep(i, n) link[i] = i;
	}
	int find(int x) {
		if(x == link[x]) return x;
		return link[x] = find(link[x]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(size[a] < size[b]) swap(a, b);
		size[a] += size[b];
		link[b] = a;
		mx = max(mx, size[a]);
	}
	int mx_() {
		return mx;
	}
	
 
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    int comp = n;
 
    dsu_cpbook dsu(n);
    rep(i, t) {
    	int u1, v1;
    	cin >> u1 >> v1;
    	u1--,v1--;
    	if(!dsu.same(u1, v1)){
    		comp--;
    		dsu.unite(u1, v1);
    	}
    	cout << comp << ' ' << dsu.mx_() << '\n';
    }
 
}
