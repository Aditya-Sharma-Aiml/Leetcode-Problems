class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i=0 ; i<n ; i++){
            //Each value x belongs at index x-1
            int index = abs(nums[i])- 1;
            // exist num ko uske index pe -ve krke rakh lo
            if(nums[index] > 0) nums[index] = -nums[index];
            // else 
            //leave +ve if again exist any num
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        return ans;


    }
};