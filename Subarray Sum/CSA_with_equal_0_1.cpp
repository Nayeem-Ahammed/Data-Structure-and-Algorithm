// Statement: Given a binary array, 
// count how many contiguous subarrays contain an 
// equal number of 0s and 1s.

#include <bits/stdc++.h>
using namespace std;

int countSubarray_with_equal01(vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> mp;
    int sum = 0, count = 0;

    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) a[i]--;
        sum += a[i];

        if(mp.find(sum) != mp.end()) 
            count += mp[sum];
        mp[sum]++;
    }
    return count;
}
int main() {
    vector <int> a = {1, 0, 0, 1, 0, 1, 1};
    cout << countSubarray_with_equal01(a) << endl;
}