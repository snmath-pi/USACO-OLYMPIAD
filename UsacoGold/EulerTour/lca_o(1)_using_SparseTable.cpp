#include<bits/stdc++.h>
using namespace std;



const int N = 2e5 + 10;
vector<vector<int>> g(N);
vector<int> first(N), height(N);


int T = 0;
vector<int> euler;
void dfs(int from, int par) {
    euler.push_back(from);
    if(first[from]==-1) first[from]=euler.size()-1;
    for(auto to: g[from]) {
        if(to != par) {
            height[to] = height[from]+1;
            dfs(to, from);
            euler.push_back(from);
        } 
    }
}
const int K = 25;
int st[K][4*N];
int lg[4*N];

int fun(int x, int y) {
    return (height[x] > height[y] ? y : x);
}
void RMQ() {
    lg[1] = 0;
    for (int i = 2; i < 4*N; i++)
        lg[i] = lg[i/2] + 1;

    for(int i=0; i<euler.size(); i++) {
        st[0][i] = euler[i];
    }
    for(int i=1; i<=K; i++) {
        for(int j=0;j+(1<<i)-1<euler.size();j++) {
            st[i][j] = fun(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;

    cin >> n >> q;
    for(int i=0;i<n;i++)first[i]=-1;
    height[0] = 1;
    for(int i=1; i<n; i++) {
        int x; cin >> x;
        g[i].push_back(--x); g[x].push_back(i);
    }
    dfs(0, -1);
    
    RMQ();    

    auto lca = [&](int a, int b)->int {
        int x = first[a], y = first[b];
        if(x>y)swap(x,y);
        int i = lg[y-x+1];

        return min(st[i][x], st[i][y-(1<<i)+1]);
    };

    auto dis =[&](int a, int b) ->int {
        return height[a] + height[b] - 2 * height[lca(a, b)];
    };
    for(int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        cout << lca(a,b)+1 << '\n';
    }
}
