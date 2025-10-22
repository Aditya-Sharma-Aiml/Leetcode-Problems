class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> seen;
        int count = 0;
        for (int num : nums) {
            if (seen.count(num - diff) && seen.count(num - 2 * diff))
                count++;
            seen.insert(num);
        }
        return count;
    }
};