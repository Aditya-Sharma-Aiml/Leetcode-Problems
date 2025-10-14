class Solution {
public:
    int sumByDivisor(vector<int>&nums , int div){
        int sum = 0;
        //summation of division values:
        for(int i=0 ; i<nums.size() ; i++){
            sum += ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        if(n > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high){

            int mid = low + (high - low)/2;
            //if divisor is valid go for smallest
            if(sumByDivisor(nums,mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
