// Statement: Given a binary array (only 0s and 1s), find the longest contiguous subarray in which the count of 0s and 1s are equal.
// Link: GeeksforGeeksLongest Subarray With Equal Number of 0s and 1s 
// GeeksforGeeks

// Also, the equivalent problem on LeetCode is “Contiguous Array” 
// LeetCode

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &a, int n) {
    int balance = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) a[i]--;
        balance += a[i];

        if(mp.find(balance) != mp.end()) 
            ans = max(ans, i-mp[balance]);
        else mp[balance] = i;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    cout << findMaxLength(a, n) << endl;
}