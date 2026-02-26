
// ou are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Recursive(int n) {
    if(n <= 1) return 1;
    return Recursive(n-1) + Recursive(n-2);
}

const int N = 1e6 + 5;
ll dp[N];
ll Memo(int n) {
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = Memo(n-1) + Memo(n-2);
}

ll Tabu(int n) {
    vector<ll> dp(n+1, -1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

ll Tabu_spaceOptimized(int n) {
    if(n <= 1) return 1;
    ll p2 = 1, p1 = 1;
    for(int i = 2; i <= n; i++) {
        ll cur = p1 + p2;
        p2 = p1;
        p1 = cur;
    }
    return p1;
}

// TC : O(log N) <- for n <= 1e18 , modulo
struct Matrix {
    ll a[2][2];
};
const int mod = 1e9+7;
Matrix multiply(Matrix x, Matrix y) {
    Matrix res;
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            res.a[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                res.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
                res.a[i][j] %= mod;
            }
        }
    }
    return res;
}
Matrix power(Matrix base, ll n) {
    Matrix res;
    
    // identity matrix
    res.a[0][0] = 1, res.a[0][1] = 0;
    res.a[1][0] = 0, res.a[1][1] = 1;

    while (n > 0) {
        if(n & 1) res = multiply(res, base);
        base = multiply(base, base);
        n >>= 1;
    }
    return res;
}
ll fibo_matrix(ll n) {   // | F(n+1) F(n)  |
    if(n == 0) return 0;  // | F(n)   F(n-1)|

    Matrix T;
    T.a[0][0] = 1, T.a[0][1] = 1;
    T.a[1][0] = 1, T.a[1][1] = 0;

    Matrix res = power(T, n-1);
    return res.a[0][0];
}
/*  Fibo = 0, 1, 1, 2, 3, 5, 8,...
*   Climb = 1, 1, 2, 3, 5, 8,...
*   so, Climb(i) = Fibo(i+1);
*/
ll climb_matrix(ll n) {
    return fibo_matrix(n+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(dp, dp+N, -1);
    int n; cin >> n;

    cout << "Recursive = " << Recursive(n) << endl;
    cout << "Memo = " << Memo(n) << endl;
    cout << "Tabu = " << Tabu(n) << endl;
    cout << "Tabu_spaceOp = " << Tabu_spaceOptimized(n) << endl;
    cout << "matrix = " << climb_matrix(n) << endl;

    return 0;
}

