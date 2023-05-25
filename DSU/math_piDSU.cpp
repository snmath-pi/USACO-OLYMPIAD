#include<bits/stdc++.h>
using namespace std;
struct dsu {
    int comps;
    vector<int> par, sz, es;
    dsu(int x) {
        par.resize(x); sz.resize(x), es.resize(x);
        comps = x;
        for(int i=0; i<x; i++) {
            par[i] = i;
            sz[i] = 1;
            es[i] = 0;
        }
 
    }
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) {
            es[a]++;
            return;
        }
        if(sz[a] < sz[b]) {
            swap(a, b); 
        }
        par[b] = a;
        sz[a] += sz[b];
        es[a] += es[b] + 1;
        comps--;
    }
    bool same(int i, int j) {return find(i) == find(j);}
    int size(int x) {return sz[find(x)];}
    int edges(int x) {return es[find(x)];};
    int components()  {return comps;}
 
};

        
