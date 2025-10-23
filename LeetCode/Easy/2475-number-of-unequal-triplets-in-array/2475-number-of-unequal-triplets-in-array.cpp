class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;  // count frequency of each number
        
        int n = nums.size();
        int ans = 0;
        int prev = 0, next = n;
        
        for (auto [num, count] : freq) {
            next -= count;                  // remaining elements after current group
            ans += prev * count * next;     // triplets formed with distinct groups
            prev += count;                  // add current group to previous count
        }
        return ans;
    }
};