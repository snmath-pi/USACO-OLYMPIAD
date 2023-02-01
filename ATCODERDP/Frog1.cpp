/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int N;
map<int, int> mp;
int dp[200000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> N;
    vector<int> height(N);
    for(int i=0; i<N; i++) {
        cin >> height[i];
    }
    dp[0] = 0;// since he is already at the first tile
    dp[1] = abs(height[1] - height[0]); // only one way to reach second tile(i.e jump once)
    // dp[i] -> min total cost to reach ith tile
    for(int i=2; i<N; i++) {
        dp[i] = 1e9;
        dp[i] = min(dp[i], dp[i-2] + abs(height[i] - height[i-2])); // min cost for ith if he came from i-2th tile
        dp[i] = min(dp[i], dp[i-1] + abs(height[i] - height[i-1])); // ...
        
    }
    cout << dp[N-1]; // cost for Nth tile (0 based indexing)
    
    return 0;
}
