/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int N, M, a, b, s_a, s_b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> N >> M;
    vector<int> adj[N];
    vector<bool> vis(N, 0);
    vector<bool> cyclic_vertec(N, 0);
    for(int i=0; i<M; i++) {
        cin >> a >> b >> s_a >> s_b;
        a--, b--;
        (s_a < s_b)?adj[a].push_back(b):adj[b].push_back(a);

    }
    function<void(int, int)> dfs = [&](int i, int j) {
        vis[j] = 1;
        if(j == i) {
            cyclic_vertec[j] = 1;
            return;
        }
        for(int U:adj[j]){
            if(!vis[U]) dfs(i, U);
        }
    };
    for(int i=0; i<N; i++) {
        int starting_vertex = i;
        for(int j:adj[i]) {
            dfs(starting_vertex, j);
        }
        vis.assign(N, 0);
    }
    int total_cyclic_vertex = 0;
    for(auto x:cyclic_vertec) total_cyclic_vertex += (x == 1);
    cout << total_cyclic_vertex << "\n";
    
    return 0;
}
