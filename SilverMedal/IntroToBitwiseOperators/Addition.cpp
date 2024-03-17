#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int m = s.size();
	if(s[0] == s[m-1]) {
		int ok = 0;
		for(int l=1, r = m-2; l < r; l++, r-- ){
			if(s[l] > s[r]) ok = 1;
		}
		if(ok) {
			if(n % 2) {
				reverse(begin(s), end(s));
				cout << s << '\n';
			} else {
				string t = s;
				reverse(begin(t), end(t));
				cout << t + s << '\n';
			}
		} else {
			if(n % 2) {
				string t = s;
				reverse(begin(t), end(t));
				cout << s + t << '\n';;
			} else {
				cout << s << '\n';
			}
		}
		return;
	}
	if(s[0] < s[m-1]) {
		if(n % 2 == 0) {
			cout << s << '\n';
		} else {
			string t = s; reverse(begin(t), end(t));
			cout << s + t << '\n';
		}
	} else {

		string t = s; reverse(begin(t), end(t));
		if(n % 2 == 0) {
			cout << t + s << '\n';
		} else {
			cout << t << '\n';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	for(;T--;) {
		solve();
	}	
}
