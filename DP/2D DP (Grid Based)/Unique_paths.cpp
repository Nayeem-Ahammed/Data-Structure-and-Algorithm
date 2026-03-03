
// 0,0 -> n,m
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int rec(int i, int j, vector<vector<int>>& dp) {
    if(i < 0 or j < 0) return 0;
    if(i == 0 and j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = rec(i-1, j, dp) + rec(i, j-1, dp);
}

int tabu(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 1));

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
int tabu_space_opmized(int n, int m) { 
    vector<int> dp(m, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            dp[j] += dp[j-1];
        }
    }
    return dp[m-1];
}
int Combinatorics (int n, int m) { // best for large constraints 
    ll res = 1;
    int N = n + m - 2;
    int r = min(m-1, n-1);

    for(int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }
    return res;
}

int main() {

    int n = 7, m = 3;
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << rec(n-1, m-1, dp) << '\n';
    cout << tabu(n, m) << '\n';
    cout << tabu_space_opmized(n, m) << '\n';

    cout << Combinatorics(n, m) << '\n';
    return 0;
}
// output : 28
