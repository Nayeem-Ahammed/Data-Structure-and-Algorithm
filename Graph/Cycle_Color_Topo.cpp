// for DAG (Directed Acyclic Graph)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis, topo, color;
bool hasCycle = false;

void dfs(int u) {
    vis[u] = 1;
    color[u] = 1; // Gray
    for(int v : g[u]) {
        if(color[v] == 0) {
            dfs(v);
        }
        else if(color[v] == 1) {
            hasCycle = true;
        }
    }

    color[u] = 2;
    topo.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    color.resize(n+1, 0);
    topo.clear();

    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); // DAG
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }


    if(hasCycle) {
        cout << "topo sort not possible\n";
    }
    else {
        reverse(topo.begin(), topo.end());
        for(int u : topo) cout << u <<" "; 
    }
}

/*
    # Coloring in DFS
    0 -> White : unvisited
    1 -> Gray  : in current DFS path (recursion stack)
    2 -> Black : fully processed
*/