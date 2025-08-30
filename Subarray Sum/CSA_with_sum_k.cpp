// given an array and a terget k.
// count the number of subarray such that sum of subarray is k.

#include <bits/stdc++.h>
using namespace std;

int countSubarraySum(vector<int> &a, int k) {
    int n = a.size();
    unordered_map<int, int> seen;
    int sum = 0, count = 0;

    seen[0] = 1;
    for(int i = 0; i < n; i++) {
        sum += a[i];

        if(seen.find(sum-k) != seen.end()) 
            count += seen[sum-k];
        seen[sum]++;
    }
    return count;
}
int main() {
    vector<int> a = {1, 2, 3};
    int k = 3;
    cout << countSubarraySum(a, k) << endl;
}