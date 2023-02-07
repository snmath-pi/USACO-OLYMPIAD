/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

constexpr int mxN = 3e5;
vector<vector<i64>> cows(mxN);
bool vis[mxN];
void Y() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> position(N);
    for(int i=0; i<N; i++) {
        cin >> position[i][0] >> position[i][1];
    }
    for(int i=0; i<M; i++) {
        int U, V;
        cin >> U >> V;
        cows[--U].push_back(--V);
        cows[V].push_back(U);
    }
    auto perimeter = [&](int l, int r) {
        return (2 * ( l + r));
    };
    int MINA = 1e9;
    function<void(int, int&, int&, int&, int&)> dfs = [&](int x, int& mxpx, int& mnpx, int& mxpy, int& mnpy) {
        vis[x] = 1;
        mxpx = min(mxpx, position[x][0]);
        mnpx = max(mnpx, position[x][0]);
        mxpy = min(mxpy, position[x][1]);
        mnpy = max(mnpy, position[x][1]);

        for(int y:cows[x]) {
            if(!vis[y]) {
                dfs(y, mxpx, mnpx, mxpy, mnpy);
            }
        }
    };
    // O(M + N) better solution than USACO Tutorial
    // author:math_pi
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            int mxpx = 1e9, mnpx = -1e9, mxpy = 1e9, mnpy = -1e9;
            dfs(i, mxpx, mnpx, mxpy, mnpy);
            int X = perimeter(mnpx - mxpx, mnpy - mxpy);
            MINA = min(MINA, X);

        }
    }
    cout << MINA;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("fenceplan.in", "r", stdin);
    // freopen("fenceplan.out", "w", stdout);
    Y();
    
    return 0;
}
