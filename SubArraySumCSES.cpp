/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std ;
using i64 = long long;
 
i64 A[213456]; 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, X;
    cin >> N >> X;
    
    i64 TOT = 0;
    unordered_map<i64, i64> mp;
    mp[0] = 1;
    for(i64 i=0, S=0; i<N; i++) {
        cin >> A[i];
        S += A[i];
        TOT += mp[S - X];
        mp[S]++;
        
    }
    cout << TOT;
    
    return 0;
}
