/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using ll = long long;
void setIO(string s) { 
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
}

int phi(int n) {
	ll res = n;
	for(ll i=2; i * i <=n; i++) {
		if(n % i == 0) {
			while(n % i == 0) {n /= i;}
			res -= res / i;
		}
	}
	if(n > 1) res -= res / n;
	return res;
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << phi(12);
    return 0;
}
