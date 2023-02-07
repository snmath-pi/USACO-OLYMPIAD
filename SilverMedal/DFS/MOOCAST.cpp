/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

vector<bool> vis;
void Y() {
    int N;
    cin >> N;
    vector<array<int, 3>> A;
    for(int i=0; i<N; i++) {
        int x, y, R;
        cin >> x >> y >> R;
        A.push_back({x, y, R});

    }
    vector<vector<bool>> connected(N, vector<bool> (N, 0));
    function<i64(int)> reachable = [&](int C) {
        vis[C] = 1;
        i64 reached = 1;
        for(int i=0; i<(int) connected.size(); i++) {
            if(!vis[i] && connected[C][i]) {
                vis[i] = 1;
                reached += reachable(i);
            }
        }
        return reached;
    };

    auto check = [&](int cx, int cy, int x, int y, int r) {
        i64 D = (x - cx) * 1ll * (x- cx) + (y - cy) * 1ll * (y - cy);
        return (D <= r * 1ll * r);
    };
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            connected[i][j] = (check(A[j][0], A[j][1], A[i][0], A[i][1], A[i][2]));
        }
    }
    i64 max_cows = 0;
    for(int i=0; i<N; i++) {
        vis.assign(N, 0);
        max_cows = max(max_cows, reachable(i));
    }
    cout << max_cows;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    Y();
    
    return 0;
}
