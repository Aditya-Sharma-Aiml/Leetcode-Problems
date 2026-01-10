class Solution {
public:
    void generateCombinations(int idx, vector<int>&ds,int target, vector<int>&nums, vector<vector<int>>&ans ){

        if (nums.size() == idx)
            return;

        if (target == 0){
            ans.push_back(ds);
            return;
        }
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            // The same number may be chosen from candidates an unlimited number of times. => we will not increment idx so that we can choose again same value
            generateCombinations(idx, ds, target - nums[idx], nums, ans);
            ds.pop_back();
        }

        generateCombinations(idx+1, ds, target,  nums, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        generateCombinations(0, ds,target, candidates , ans);
        return ans;
    }
};