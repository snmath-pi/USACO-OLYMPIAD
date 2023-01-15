/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
// Note: use long long as sums can be very large ^_^~math_pi
#include<iostream>
using namespace std ;
using i64 = long long;
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
void solve() {
	i64 n, q;
	cin >> n >> q;
	i64 a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(i) a[i] += a[i-1];
	}
	for(int i=0; i<(i64)q; i++) {
		int l, r;
		cin >> l >> r;
		r--;
		if(l >0)cout << (i64)a[r] - a[l-1] << "\n";
		else cout << a[r] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	int t = 1 ;
	//cin >> t ;
	while(t--){
		solve() ;
	}
}
