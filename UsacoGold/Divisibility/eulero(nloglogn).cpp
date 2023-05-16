/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using ll = long long;
void setIO(string s) { 
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
}
vector<ll> phi_1_to_n(ll n) {
	vector<ll> phi(n+1);
	for(int i=0; i <= n; i++) {
		phi[i] = i;
	}
	for(int i=2; i<=n; i++) {
		if(phi[i] = i) {
			for(int j=i; j <= n; j+=i) {
				phi[j] -= phi[j] / i;
			}
		}
	}
	return phi;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}
