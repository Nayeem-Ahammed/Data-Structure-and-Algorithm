#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int rec (int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i < 0 or j < 0) return 0;
    if(grid[i][j] == 1) return 0;
    if(i == 0 and j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = rec (i-1, j, grid, dp) + rec (i, j-1, grid, dp);
}

int tabu (vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    if(grid[0][0] == 1 or grid[n-1][m-1] == 1)
        return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) dp[i][j] = 1;
            else if (grid[i][j] == 0) {
                int left = (j > 0 ? dp[i][j-1] : 0);
                int up = (i > 0 ? dp[i-1][j] : 0);
                dp[i][j] = left + up;
            }
        }
    }
    return dp[n-1][m-1];
}

int tabu_space_optimized(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if(grid[0][0] == 1 or grid[n-1][m-1] == 1)
        return 0;

    vector<int> dp(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 and j == 0) dp[j] = 1;
            else if(grid[i][j] == 1) dp[j] = 0;
            else {
                int left = (j > 0 ? dp[j-1] : 0);
                int up = (i > 0 ? dp[j] : 0);
                dp[j] = left + up;
            }
        }
    }
    return dp[m-1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << tabu(grid) << '\n'; 
    cout << tabu_space_optimized(grid) << '\n';
    
    return 0;
}
// output : 2
