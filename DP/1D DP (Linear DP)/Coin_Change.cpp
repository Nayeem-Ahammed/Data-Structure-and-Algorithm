#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TC : O(n * amount), SC : O(n)
int coinChangeMin(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for(int c : coins) {
            if(i - c >= 0 and dp[i - c] != INT_MAX) 
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// TC : O(n * amount), SC : O(n)
ll coinChangeWays(vector<int> &coins, int amount) {
    vector<ll> dp(amount + 1, 0);
    dp[0] = 1;

    for(int c : coins) {
        for(int i = c; i <= amount; i++) {
            dp[i] += dp[i-c];
        }
    }

    return dp[amount];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChangeMin(coins, amount) << '\n'; // Output : 3

    amount = 5;
    cout << coinChangeWays(coins, amount); // Output : 4
    return 0;
}