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

int mult(int a, int b) {
	int c = 0;
	while(b) {
		if(b & 1 == 1) {
			c = add(a, c);
		}
		a <<= 1;
		b >>= 1;
	}
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	cout << add(a, b) << ' ' << mult(a, b) << '\n';
}
