#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    
    // Adjacency Matrix
    int g[n+1][n+1] = {0}; // memset(g, 0, sizeof(g));
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';


    // Adjacency List
    // vector<int> G[n+1];
    vector<vector<int>> G(n+1);
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // for undirected
    }

    for(int i = 1; i <= n; i++) {
        cout << i <<" --> ";
        for(int v : G[i]) {
            cout << v <<", ";
        }
        cout << '\n';
    }

}
