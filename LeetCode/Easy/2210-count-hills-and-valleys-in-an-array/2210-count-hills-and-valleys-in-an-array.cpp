class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0; // hill or valley not possible

        int count = 0;
        int prev = 0;

        for (int i = 1; i < n - 1; i++) {
            // skip adjacent
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if ((nums[prev] < nums[i] && nums[i] > nums[i + 1]) || // hill
                (nums[prev] > nums[i] && nums[i] < nums[i + 1])) { // valley
                count++;
            }

            // update last distinct index
            prev = i;
        }

        return count;
    }
};
