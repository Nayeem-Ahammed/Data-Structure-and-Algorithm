#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i < 0 or j < 0) return INT_MAX;
    if(i == 0 and j == 0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = grid[i][j] + min(rec(i-1, j, grid, dp), rec(i, j-1, grid, dp));
}

int tabu(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) dp[i][j] = grid[i][j];
            else {
                int Left = (j > 0 ? dp[i][j-1] : INT_MAX);
                int Up = (i > 0 ? dp[i-1][j] : INT_MAX);
                dp[i][j] = grid[i][j] + min(Left, Up);
            }
        }
    }
    return dp[n-1][m-1];
}

int tabu_space_optimized(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) dp[j] = grid[i][j];
            else {
                int Left = (j > 0 ? dp[j-1] : INT_MAX);
                int Up = (i > 0 ? dp[j] : INT_MAX);
                dp[j] = grid[i][j] + min(Left, Up);
            }
        }
    }
    return dp[m-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << rec(n-1, m-1, grid, dp) << '\n';

    cout << tabu(grid) << '\n';
    cout << tabu_space_optimized(grid) << '\n';
    
    return 0;
}
// Output : 7