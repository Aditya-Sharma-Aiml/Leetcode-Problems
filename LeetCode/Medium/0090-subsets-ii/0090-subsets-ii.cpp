class Solution {
public:
    void findSubset(int idx, vector<int>&ds, 
                            vector<int>&nums, vector<vector<int>>&ans){
        ans.push_back(ds);// subsets put into ans
        for(int i=idx ; i<nums.size(); i++){
            //skip duplicate
            if(i> idx && nums[i]==nums[i-1])continue;

            ds.push_back(nums[i]);
            findSubset(i+1, ds, nums, ans);
            ds.pop_back();
        }

    }
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        //sorting is imp to maintain duplicates be adjacent
        findSubset(0,ds,nums,ans);
        return ans;
    }
};