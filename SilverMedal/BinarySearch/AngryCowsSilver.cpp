/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

int N, K, X, iter = 100;
void Y() {
    cin >> N >> K;
    std::vector<int> haybales(N, 0);
    for(int i=0; i<N; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());
    auto good = [&](int Y) {
        int cows_needed = 1;
        int curr_radii = haybales[0];
        for(int i=0; i<N; i++) {
            if(haybales[i] >= curr_radii && haybales[i] <= curr_radii + 2 * Y) continue;
            else {
                cows_needed++;
                curr_radii = haybales[i];
            }
        }
        return cows_needed <= K;
    };
    // 1 3 8 10 18 20 25
    // 
    i64 L = 1, R = 1e9;
    while(R > L) {
        i64 M = (L + R ) / 2;
        if(good(M)) {
            R = M;
        }else L = M + 1;
    }
    cout << L;


}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    Y();
    
    return 0;
}
