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


// Matrix Exponentiation for n <= 1e18
// TC : O(log n)
struct Matrix {
    int a[2][2];
};
const int mod = 1e9+7;
Matrix mul(Matrix x, Matrix y) {
    Matrix res;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            res.a[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                res.a[i][j] = (res.a[i][j] + 1LL * x.a[i][k] * y.a[k][j] % mod) % mod;
            }
        }
    }
    return res;
}
Matrix power(Matrix base, ll p) {
    Matrix res;
    res.a[0][0] = 1, res.a[0][1] = 0;
    res.a[1][0] = 0, res.a[1][1] = 1;

    while (p > 0) {
        if(p & 1) res = mul(res, base);
        base = mul(base, base);
        p >>= 1;
    }
    return res;
}
ll matrix_fibo(ll n) {
    if(n == 0) return 0;
    Matrix T;
    T.a[0][0] = 1, T.a[0][1] = 1;
    T.a[1][0] = 1, T.a[1][1] = 0;

    Matrix res = power(T, n-1);
    return res.a[0][0];
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

    cout << "Matrix Exp = " << matrix_fibo(n) << nl;
    return 0;
}
