#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// you vann't rob two adjacent house --> find max profit

const int N = 2e5 + 5;
ll dp[N];

ll Memo(int i, vector<int> a) {
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];

    ll skip = Memo(i-1, a);
    ll take = a[i] + Memo(i-2, a);

    return dp[i] = max(skip, take);
}
ll Tabu(vector<int> a) {
    int n = a.size();
    if(n == 0) return 0;
    if(n == 1) return a[0];

    vector<ll> dp(n);
    dp[0] = a[0], dp[1] = max(a[0], a[1]);

    for(int i = 2; i < n; i++) 
        dp[i] = max(dp[i-1], a[i] + dp[i-2]);
    
    return dp[n-1];
}
ll spaceOptimized(vector<int> a) {
    ll p1 = 0, p2 = 0;
    for(int x : a) {
        ll cur = max(p1, x + p2);
        p2 = p1, 
        p1 = cur;
    }
    return p1;
}


// ==========================================================
// first and last house are adjacent
ll houseRobberCircular(vector<int> &a) {
    ll ans1 = 0, ans2 = 0; // 0 - n-2 && 1 - n-1
    ll p1 = 0, p2 = 0;
    int n = a.size();
    if(n == 1) return a[0];

    for(int i = 0; i < n-1; i++) {
        ll cur = max(p1, a[i] + p2);
        p2 = p1;
        p1 = cur;
    }
    ans1 = p1;

    p1 = p2 = 0;
    for(int i = 1; i < n; i++) {
        ll cur = max(p1, a[i] + p2);
        p2 = p1;
        p1 = cur;
    }
    ans2 = p1;

    return max(ans1, ans2);
}

// ============================================================
// Tree Version : Can't take parent & child together
struct Node {
    ll val;
    Node *left, *right;
    Node(ll x) : val(x), left(NULL), right(NULL) {};
};
// Rob it → value + left.skip + right.skip
// Skip it → max(left) + max(right)
pair<ll, ll> dfs(Node *root) {  // {rob_this, skip_this};
    if(root == NULL) 
        return {0, 0};
    auto L = dfs(root->left);
    auto R = dfs(root->right);

    ll rob_this = root->val + L.second + R.second; // skip L, R
    ll skip_this = max(L.first, L.second) + max(R.first, R.second);

    return {rob_this, skip_this};
}
ll houseRobberTree(Node *root) {
    auto ans = dfs(root);
    return max(ans.first, ans.second); // {rob_this, skip_this}
}

// =================================================================
// DELETE and EARN
// If you pick number x, you cannot pick x-1 or x+1.
ll deleteAndEarn(vector<int> &a) {
    if(a.empty()) return 0;

    int limit = *max_element(a.begin(), a.end());
    vector<ll> points(limit+1, 0);

    for(int x : a) points[x] += x;

    // Now run House Robber on array d
    ll p1 = 0, p2 = 0;
    for(int i = 0; i <= limit; i++) {
        ll cur = max(p1, p2 + points[i]);
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));

    cout << "Memo = " << Memo(n-1, a) << '\n';
    cout << "Tabu = " << Tabu(a) << '\n';
    cout << "Space Optimized = " << spaceOptimized(a) << '\n';
    cout << "Circular House = " << houseRobberCircular(a) << '\n';


    vector<Node*> Tree(n+1);
    // create nodes
    for(int i = 1; i <= n; i++) {
        // ll x; cin >> x;
        Tree[i] = new Node(a[i-1]);
    }
    // connect child
    for(int i = 1; i <= n; i++) {
        if(2*i <= n) 
            Tree[i]->left = Tree[2*i];
        if(2*i + 1 <= n) 
            Tree[i]->right = Tree[2*i + 1];
    } 
    cout << "TreeHouse Robber = " << houseRobberTree(Tree[1]) << '\n'; 
    cout << "Delete & Earn = " << deleteAndEarn(a) << '\n';
    return 0;
}
