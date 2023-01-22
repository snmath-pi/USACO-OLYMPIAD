/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 X;
    cin >> X;
    i64 L = 0, R = X;
    int iter = 100;
    auto good = [&](i64 a) {
        return (a * a <= X);
    };
    while(iter--) {
        int M = L + (R - L) / 2;
        if(good(M)) {
            L = M;
        } else R = M - 1;
    }
    cout << L;
    
    return 0;
}
