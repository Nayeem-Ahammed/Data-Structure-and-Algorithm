#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis, tin, tout;
int Time;
void DFS(int u) {
    vis[u] = 1;
    tin[u] = ++Time;

    for(int v : g[u]) {
        if(!vis[v]) {
            DFS(v);
        }
    }

    tout[u] = ++Time;
}

int main() {
    int n, m; cin >> n >> m;
    
    g.resize(n+1);
    vis.resize(n+1, 0);
    Time = 0;
    tin.resize(n+1);
    tout.resize(n+1);

    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) DFS(i);
    }
    for(int i = 1; i <= n; i++) {
        cout << i <<" => " << tin[i] <<" " << tout[i] << '\n';
    }
}


/*
    Node u is ancestor of v iff:
    tin[u] < tin[v] && tout[u] > tout[v]
*/