#include<bits/stdc++.h>
using namespace std;
 
 
const int N = 2e5 + 10;
vector<int> g[2*N+1], first(2*N+1), height(N*2+1);
vector<int> tree(8*N);
 
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
int fun(int x, int y) {
    return min(x, y);
}
void build(int x = 0, int lx = 0, int rx = euler.size()) {
    if(rx - lx == 1) {
        if(lx<euler.size()) tree[x] = euler[lx];
        return;
    }
    int mid = lx + rx >> 1;
    build(2*x+1,lx,mid);
    build(2*x+2,mid,rx);
    tree[x] = fun(tree[2*x+1], tree[2*x+2]);
}
 
int get(int l, int r, int x = 0, int lx = 0, int rx = euler.size()) {
    if(rx<=l || lx>=r) return INT_MAX;
    if(rx<=r&&lx>=l)return tree[x];
 
    int mid = lx + rx >> 1;
    return fun(get(l,r,2*x+1,lx,mid),get(l,r,2*x+2,mid,rx));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
 
    cin >> n >> q;
    for(int i=0;i<n;i++)first[i]=-1;
    height[0] = 1;
    for(int i=1; i<n; i++) {
        int x; cin >> x; --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(0, -1);
    for(auto x: euler) x = height[x];
    build();
 
    auto lca = [&](int a, int b)->int {
        a = first[a], b = first[b];
        if(a>b)swap(a,b);
        return get(a,b+1);
    };
    for(int i=0; i<q; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        cout << lca(a, b)+1 << '\n';
    }
}
