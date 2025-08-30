// Statement: Given an array with positive and negative integers, 
// find the length of the longest subarray whose sum is zero.

// max lenght of sub array with sum = 0.
#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> firstSeen;
    int maxLen = 0, prefixSum = 0;

    firstSeen[0] = -1;
    for(int i = 0; i < n; i++) {
        prefixSum += a[i];
        if(firstSeen.find(prefixSum) != firstSeen.end()) {
            maxLen = max(maxLen, i - firstSeen[prefixSum]);
        } else firstSeen[prefixSum] = i;
    }
    return maxLen;
}
int main() {
    vector <int> a = {15, -2, 2, -8, 1, 7, 10};
    cout << maxLength(a) << endl;
}