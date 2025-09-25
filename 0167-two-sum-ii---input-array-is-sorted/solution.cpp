class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(nums[left]+nums[right]!=target){

            int sum = nums[left] + nums[right];
            if(sum<target) left++;
            else right--;

        }
        return {left+1, right+1};
    }
};
