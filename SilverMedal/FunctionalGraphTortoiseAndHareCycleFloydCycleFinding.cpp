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
 
int t, n;

int f(int x) {
	return (7 * x + 5) % 12;
}

pi FloydCycleFinding(int x0) {
	// 1st part: finding k * mu, hare's speed is 2 * tortoise's;
	int tortoise = f(x0), hare = f(f(x0));
	while(tortoise != hare) {tortoise = f(tortoise); hare = f(f(hare)); }
	// 2nd part finding mu, hare and tortoise move at same speed
	int mu = 0; hare = x0;
	while(tortoise != hare) {tortoise = f(tortoise); hare=f(hare); mu++; }
	// 3rd part find lambda, hare moves and tortoise stays;
	int lambda = 1; tortoise = mu; hare = f(tortoise);
	while(tortoise != hare) {hare= f(hare); lambda++;}

	return {mu, lambda};
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pi p = FloydCycleFinding(4);
	cout << p.fi << ' ' << p.se << '\n';

}
