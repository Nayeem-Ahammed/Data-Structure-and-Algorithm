// for DAG (Directed Acyclic Graph)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis, topo;
void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
    }
    topo.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); // DAG
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    reverse(topo.begin(), topo.end()); // must reverse

    for(int u : topo) cout << u <<" ";
}