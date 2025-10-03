class Solution {
private:
    void recurPermute(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // track what we’ve used at this level

        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) {
                continue; // skip duplicates
            }
            used.insert(nums[i]);

            // Swap in
            swap(nums[i], nums[idx]);

            // Look for next position
            recurPermute(idx + 1, nums, ans);

            // Swap out
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

