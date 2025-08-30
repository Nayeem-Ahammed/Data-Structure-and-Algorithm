// Statement: Given a non-negative integer array and a target sum k, 
// find the longest contiguous subarray whose sum is exactly k.

#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &a, int k) {
    unordered_map<int, int> firstSeen;
    int sum = 0, maxLen = 0;

    firstSeen[0] = -1;
    for(int i = 0; i < a.size(); i++) {
        sum += a[i];

        if(firstSeen.find(sum - k) != firstSeen.end()) 
            maxLen = max(maxLen, i - firstSeen[sum - k]);
        else firstSeen[sum] = i;
    }
    return maxLen;
}
int main() {
    vector <int> a = {1, 2, 3};
    int k = 3;
    cout << maxLength(a, k) << endl;
    return 0;
}