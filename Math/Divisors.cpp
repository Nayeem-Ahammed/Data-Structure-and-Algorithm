#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//## Bruteforce Method
// TC = O(n), works for n <= 1e6
// Too slow for cp when n <= 1e12
vector<int> bruteForce(int n) {
    vector<int> divisors;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) 
            divisors.push_back(i);
    }
    return divisors;
}

//## Optimized Method 
// TC = O(sqrt(n)), work for n <= 1e12
vector<int> optimized(int n) {
    vector<int> divisors;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n / i) 
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> divisors = optimized(n);
    for(int d : divisors) cout << d <<" ";
    cout << endl;
    
    return 0;
}
