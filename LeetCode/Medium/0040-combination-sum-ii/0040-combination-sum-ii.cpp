class Solution {
public:
    void findCombinations(int idx, int target, vector<int>&ds, vector<int>&nums,  vector<vector<int>>&ans){
        // base case
        if (target == 0){
            ans.push_back(ds);
        }
        //picking all start -> idx to n-1 element 
        for(int i=idx; i<nums.size(); i++){
            // handle duplicate combinations
            if (i>idx && nums[i] == nums[i-1]) continue;

            if (nums[i] > target) break;
            // picking ith value
            ds.push_back(nums[i]);
            findCombinations(i+1, target - nums[i], ds, nums, ans);
            ds.pop_back(); // backtrack
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // imp step to handle duplicate
        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0, target, ds, candidates, ans);
        return ans;

    }
};