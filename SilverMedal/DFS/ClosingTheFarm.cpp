/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;

constexpr int mxN = 4000;
int N, M, u, v, nodes = 0;
vector<vector<int>> adj(mxN);
vector<bool> vis(mxN), closed(mxN);
void Y() {
  
  cin >> N >> M;

  for(int i=0; i<M; i++) {
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  vector<int> ord(N);
  for(int i=0; i<N; i++) {
    cin >> ord[i];
    --ord[i];
  }
  function<void(int)> dfs = [&](int i) {
    if(vis[i] || closed[i]) return;

    vis[i] = true;
    nodes++;
    for(auto x:adj[i]) {
      if(!vis[x]) dfs(x);
    }

  };
  dfs(0);
  cout << (nodes == N?"YES":"NO") << "\n";
  for(int i=0; i<N-1; i++) {
    nodes = 0;
    closed[ord[i]] = true;
    fill(vis.begin(), vis.end(), 0);
    dfs(ord[N-1]);
    cout << (nodes == N - i - 1?"YES":"NO") << "\n";
  }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    Y();
    
    return 0;
}
