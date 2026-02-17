class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        // target  = max banana kyunki increment hi allow hai
        // nums = [1,2,4], k = 5
        // ab  4 4 4 banana hai toh target = 4+4+4 = 4*3(max*window size) 
        // okay now 1+2+4 = 7 already hai toh isko ghata do 
        // required = target - curr_Sum

        // formula : required = nums[i] * window_size - currSum

        int l = 0, r = 0;
        int ans = 1;

        sort(nums.begin(), nums.end());

        long long currSum = 0 ;

        while(r<nums.size()){

            currSum += nums[r];

            // long long required = nums[r] * (r-l+1) - currSum;

            if((long long)nums[r] * (r-l+1) - currSum > k ){

                currSum -= nums[l];
                l++;
            }

            ans  = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};