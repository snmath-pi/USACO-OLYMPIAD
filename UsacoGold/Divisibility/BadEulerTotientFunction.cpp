#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;
// ;; EULER TOTIENT FUNCTION
// TELLS THE NUMBER OF INTEGERS WHICH ARE COPRIME TO N FROM [1, N]
// ;;** IF N IS PRIME, THEN ALL INTEGERS < N ARE COPRIME TO N I.E N-1
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    map<int, int> mp;
    for(int i=2, d=1; i*i <= n; i+=d, d=2) {
        while(n%i==0) {
            mp[i]++;
            n/=i;
        }
    }
    if(n!=1) mp[n]++;
    int64_t ret = 1;
    auto Qpow=[&](ll x, ll y) {
        int64_t lst = 1;
        while(y) {
            if(y%2) lst *= x;
            x *=x;
            y >>=1; 
        }
        return lst;
    };
    for(auto x: mp) {
        ret *= Qpow(x.fi, x.se-1) * (x.fi-1);
    }

    cout << ret;


}
