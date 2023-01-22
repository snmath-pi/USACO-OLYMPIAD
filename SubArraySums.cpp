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
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    i64 TOT = 0;
    unordered_map<i64, i64> mp;
    i64 S = 0;
    for(i64 i=0; i<N; i++) {
        S += A[i];
        if(S == X) {
            TOT++;
        }
        if(mp.find(S - X) != mp.end()) {
            TOT += mp[S-X];
        }
        
        mp[S]++;
        
    }
    cout << TOT;
    
    return 0;
}
