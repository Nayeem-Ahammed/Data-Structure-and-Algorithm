
/* # Kahn’s algorithm is used on a directed graph to:
    1. Produce a topological ordering, and
    2. Detect whether a cycle exists

It is an alternative to DFS + color and is often preferred when:
    - recursion depth is risky
    - BFS-style logic is clearer
    - you want cycle detection implicitly
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n+1);
    vector<int> ind(n+1, 0);

    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        ind[v]++;
    }

    queue <int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int v : g[u]) {
            if(--ind[v] == 0) {
                q.push(v);
            }
        }
    }

    if(topo.size() < n) {
        cout << "Cycle exits\n";
    } else {
        cout << "Topological order: \n";
        for(int v : topo) cout << v <<" ";
    }

    return 0;
}