class Solution {
public:
    void allSubsequence(int idx, int n, vector<int>ds, vector<int>&nums, vector<vector<int>>&ans){

        if(idx == n){ // base case
            ans.push_back(ds);
            return ;
        }
        // pick
        ds.push_back(nums[idx]);
        allSubsequence(idx+1, n, ds, nums, ans);

        ds.pop_back();
        // not pick
        allSubsequence(idx+1, n, ds, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>ds;
        allSubsequence(0, n, ds, nums, ans);
        return ans;
    }
};