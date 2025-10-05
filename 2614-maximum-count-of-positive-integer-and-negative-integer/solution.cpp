class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();

        int ub_zero = upper_bound(nums.begin(), nums.end(),0) - nums.begin();
        int lb_zero = lower_bound(nums.begin(), nums.end(),0) - nums.begin();
        
        int neg = lb_zero ;
        int pos = n - ub_zero ;
        return max(neg , pos); 
        
        
        // // find first positive (>0)
        // int l = 0, r = n - 1, firstPos = n;
        // while (l <= r) {
        //     int mid = l + (r - l) / 2;
        //     if (nums[mid] > 0) {
        //         firstPos = mid;
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        // int pos = n - firstPos;

        // // find first zero (>=0)
        // l = 0, r = n - 1;
        // int firstZero = n;
        // while (l <= r) {
        //     int mid = l + (r - l) / 2;
        //     if (nums[mid] >= 0) {
        //         firstZero = mid;
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        // int neg = firstZero;
        
        // return max(pos, neg);
    }
};

