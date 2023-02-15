/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;
#define F0R(i, N) for(int i=0; i<(int)N; i++)
#define FOR(i, j, N) for(int i=(int)j; i<(int)N; i++)
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define vl vector<i64>
#define vi vector<int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

constexpr int mxN = 55;
char grid[mxN][mxN];
bool vis[mxN][mxN];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int N, M;
void solve() {
    memset(grid, '.', sizeof(grid));
    memset(vis, 0, sizeof(vis));
    cin >> N >> M;
    for(int r = 0; r <N; r++) {
        for(int c = 0; c<M; c++) {
            cin >> grid[r][c];
        }
    }
    function<void(int, int)> floodfill = [&](int i, int j) {
        if(i < 0 || i >= N || j < 0 || j >=M) return;
        if(grid[i][j] == '#' || vis[i][j]) return;
        vis[i][j] = 1;
        floodfill(i-1, j); floodfill(i+1, j); floodfill(i, j-1); floodfill(i, j+1);
    };
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(grid[i][j] == 'B') {
                for(int x = 0; x < 4; x++) {
                    int now_i = i + dx[x];
                    int now_j = j + dy[x];
                    if(now_i >=0 && now_i < N && now_j >=0 && now_j < M) {
                        if(grid[now_i][now_j] == 'G') {
                            cout << "No\n";
                            return;
                        }
                        if(grid[now_i][now_j] == '.') grid[now_i][now_j] = '#';
                    }

                }
            }
        }
    }
    floodfill(N-1, M-1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(grid[i][j] == 'G' && !vis[i][j]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes" << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TT=1; 
    cin >> TT;
    while(TT--){
        solve();
    }
}
