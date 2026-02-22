#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Idea : n = p1^a1 * p2^a2 * ... * pk^ak
//        Count of divisors = (a1 + 1) * (a2 + 1) * ... * (ak + 1)
// TC = O(sqrt(n)), work for n <= 1e12
ll countDivisors(ll n) {
    ll ans = 1;
    for(ll i = 2; i*i <= n; i++) {
        int cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        ans *= (cnt + 1);
    }
    if(n > 1) ans *= 2;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll cnt = countDivisors(n);
    cout << cnt << endl;

    return 0;
}