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
    int ret = n;
    int m = n;
    // O(N^1/2) implementation
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            while(n%i==0) n/=i;
            ret -= ret / i;
        }
    }
    if(n>1) ret -= ret/n;

    cout << ret;


    // O(nloglogN) using sieve to calculate phi for each integers [1, N]
    n = m;
    vi phi(n+1);
    auto phi_1_to_n = [&](int n) {
        
        rep(i, n+1) phi[i] = i;
        rng(i, 2, n+1) {
            if(phi[i] == i) {
                for(int j=i; j<=n; j+=i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        return phi;    
    };

    phi_1_to_n(n); cout << '\n';
    rep(i, n+1) cout << phi[i] << ' ';



}
