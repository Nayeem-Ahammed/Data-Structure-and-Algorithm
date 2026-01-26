#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void DFS(int u) {
    vis[u] = 1;
    cout << u <<" "; // process node u

    for(int v : g[u]) {
        if(!vis[v]) {
            DFS(v);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    g.resize(n+1);
    vis.resize(n+1, 0);

    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) DFS(i);
    }
}
