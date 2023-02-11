// https://open.kattis.com/submissions/10464565
/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int mxN = 5005;
int N, M, a, b;
void solve(){
    vector<int> adj[N];
    vector<bool> vis(N, 0);
    vector<vector<bool>> NOT(N, vector<bool> (N, 0));
    vector<pair<int, int>> friends;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        friends.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<void(int)> dfs = [&](int i) {
        vis[i] = 1;

        for(int X:adj[i]) {
            if(!vis[X] && !NOT[i][X] && !NOT[X][i]) {
                dfs(X);
            } 
            else continue;
        }
    };
    bool ok = 1;
    for(int i=0; i<(int) friends.size(); i++) {
        NOT[friends[i].first][friends[i].second] = 1;
        NOT[friends[i].second][friends[i].first] = 1;
        // cout << friends[i].first<< "\n";
        dfs(0);
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                ok = 0;
            }
        }
        vis.assign(N, 0);
        NOT[friends[i].first][friends[i].second] = 0;
        NOT[friends[i].second][friends[i].first] = 0;


    }
    cout << (!ok?"Yes":"No") << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> N >> M && (N || M)) solve();
} 
    
