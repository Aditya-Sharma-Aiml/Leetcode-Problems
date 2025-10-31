class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;

        for(int i=0 ; i<nums.size() ; i++){
            // place a num to its ideal index (index 7 - value 8)
            int index = abs(nums[i])-1;
            // mark as exist
            if(nums[index] > 0) nums[index] = -nums[index];
            // if again exist then push into ans
            else
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};