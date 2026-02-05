class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();
        vector<int>result;

        for(int i=0; i<n; i++){

            if(nums[i] == 0) result.push_back(nums[i]);

            else if(nums[i] > 0){ // right
                int steps = abs(nums[i]);
                int newIndex = (i + steps) % n;
                result.push_back(nums[newIndex]);

            }
            else if(nums[i] < 0){ // left
                int steps = abs(nums[i]) % n;
                int newIndex = (i - steps + n ) % n;
                result.push_back(nums[newIndex]);

            }
        }
        return result;
    }
};