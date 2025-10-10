#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        // NOTE : binary search se kroge toh bhi O(n) lagega
        // kyunki tum har element ke liye check kroge na peak hai ya nhi
        vector<int> peaks;
        int n = mountain.size();

        // check from 1 to n-2 (ignoring first and last)
        for (int i = 1; i < n - 1; i++) {

            if (mountain[i] > mountain[i - 1] &&
                mountain[i] > mountain[i + 1]) {

                peaks.push_back(i);
            }
        }
        return peaks;
    }
};
