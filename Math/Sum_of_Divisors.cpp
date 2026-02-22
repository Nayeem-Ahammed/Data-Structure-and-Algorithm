#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Idea : n = p1^a1 * p2^a2 * ... * pk^ak
//        Sum of Divisors = (p1^(a1+1) - 1) / (p1 - 1) * ... * (pk^(ak+1) - 1) / (pk - 1)

// TC = O(sqrt(n)), work for n <= 1e12

ll sumOfDivisors(ll n) {
    ll sum = 1;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            ll term = 1, power = 1;

            while(n % i == 0) {
                n /= i;
                power *= i;
                term += power;
            }
            sum *= term;
        }
        
        if(n > 1) sum *= (1 + n);
        return sum;
    } 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll sum = sumOfDivisors(n);
    cout << sum << endl;

    return 0;
}