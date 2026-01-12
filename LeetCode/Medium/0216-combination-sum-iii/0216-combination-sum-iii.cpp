class Solution {
public:
    void findCombination(int start , int k, int target,
                            vector<int>&nums,vector<vector<int>>&ans)
    {

        if(target == 0 && k == 0){
            ans.push_back(nums);
            return ;
        }

        if(target > 0 && k <=0) return ;

        for(int i=start; i<=9 ;i++){

            nums.push_back(i);
            findCombination(i+1, k-1, target - i, nums, ans);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums;
        findCombination(1, k, n, nums, ans);
        return ans;
    }
};