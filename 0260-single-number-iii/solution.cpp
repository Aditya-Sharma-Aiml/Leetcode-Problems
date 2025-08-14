class Solution {
public:
    long generateMask(vector<int>&nums){
        long xorall = 0;
        for(int i=0 ;i<nums.size();i++){

            xorall ^= nums[i];
        }
        return xorall;
    }
    vector<int> singleNumber(vector<int>& nums) {
        long mask = generateMask(nums);
        long right_set  = mask & -mask;

        
        int d1=0 , d2=0;
        for(int i =0 ; i<nums.size() ;i++){
            if(nums[i] & right_set){
                d1^=nums[i];
            }
            else{
                d2^=nums[i];
            }
        }
        
        return {d1,d2};
    }
};
