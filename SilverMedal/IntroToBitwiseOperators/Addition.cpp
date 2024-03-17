#include<bits/stdc++.h>
using namespace std;

int add(int x, int y) {
	while(y) {
		int carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	cout << add(a, b) << '\n';
}
