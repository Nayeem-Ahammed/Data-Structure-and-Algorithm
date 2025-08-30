// Given an array , count the number of subarray such that 
// subarray sum = 0

#include <bits/stdc++.h>
using namespace std;

int countSubarray_with_sum_0(vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> seen;
    int sum = 0, count = 0;

    seen[0] = 1;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(seen.find(sum) != seen.end()) 
            count += seen[sum];
        seen[sum]++;
    }
    return count;
}
int main() {
    vector <int> a = {2, 0, -2, -1, 1};
    cout << countSubarray_with_sum_0(a) << endl;
}