/*
    Given a positive integer n, find the nth Fibonacci number.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TC : O(2^n)
int Recursion(int n) {
    if(n <= 1) return n;
    return Recursion(n-1) + Recursion(n-2);
}

// TC : O(n), SC : O(n)
const int N = 1e6+7;
ll dp[N];
int Memoization(int n) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = Memoization(n-1) + Memoization(n-2);
}

int Tabulation(int n) {
    if(n <= 1) return n;

    int dp[n+1];
    dp[0] = 0, dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// TC : O(n) , SC : O(1)
int Optimized(int n) {
    if(n <= 1) return n;

    int p1 = 1, p2 = 0;
    for(int i = 2; i <= n; i++) {
        int cur = p1 + p2;
        p2 = p1;
        p1 = cur;
    }
    return p1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    cout <<"Recursion = " << Recursion(n) << endl;

    fill(dp, dp+N, -1);
    cout << "Memoization = " << Memoization(n) << endl;

    cout << "Tabulation = " << Tabulation(n) << endl;

    cout << "Space Optimization = " << Optimized(n) << endl;
    return 0;
}
