
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TC = O(N log N), work for n <= 1e6
const int N = 1e6;
vector<vector<int>> divisors(N+1);

void pre() {
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i)
            divisors[j].push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pre();
    for(int i = 1; i <= 10; i++) {
        cout << i <<" = ";
        for(int d : divisors[i]) 
            cout << d <<" ";
        cout << endl;
    }

    return 0;
}