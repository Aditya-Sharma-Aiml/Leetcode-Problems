class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: find break-point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If no break-point found, reverse whole array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;  // important fix
        }

        // Step 2: find next greater element on right
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

