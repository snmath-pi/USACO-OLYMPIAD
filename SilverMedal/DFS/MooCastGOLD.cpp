/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;


void Y() {
    i64 N;
    cin >> N;
    array<i64, 2> cows[N];
    for(i64 i=0; i<N; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }
    
    auto distance = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
        return (((x1 - x2) * (x1 - x2)) + ((y1-y2) * (y1 - y2)));
    };
    auto good = [&](i64 X) {
        vector<bool> vis(N, 0);
        vector<int> begin{0};
        vis[0] = 1;
        while(!begin.empty()) {
            int K = begin.back();
            begin.pop_back();
            for(int i=0; i<N; i++) {
                if(!vis[i] && distance(cows[K][0], cows[K][1], cows[i][0], cows[i][1])<=X){
                    begin.push_back(i);
                    vis[i] = 1;
                }
            }
        }
        
        for(i64 i=0; i<N; i++) {if(!vis[i]) return false;}
        return true;
    };  
    i64 L = -1, R = 1e9;
    while(R > L + 1) {
        i64 M = (L + R) / 2;
        if(good(M)) {
            R = M;
        } else L = M;
    }
    cout << R;

}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    Y();
    
    return 0;
}
