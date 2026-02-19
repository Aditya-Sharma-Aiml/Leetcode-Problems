class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        if(n<3) return max(nums[0], nums[1]);

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        long long max3 = LLONG_MIN;

        for(int num : nums){

            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num < max1 && num > max2){
                max3 = max2;
                max2 = num;
            }
            else if(num < max2 && num > max3){
                max3 = num;
            }
        }
        if(max3 == LLONG_MIN) return max1;
        return max3;
    }
};