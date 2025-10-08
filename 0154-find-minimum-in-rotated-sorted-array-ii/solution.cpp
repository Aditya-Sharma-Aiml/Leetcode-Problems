class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0, high = nums.size()-1;
        int ans = INT_MAX;

        while(low <= high){

            int mid = low + (high - low)/2;

            //entire search space is already sorted
            if(nums[low] < nums[high]){

                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                //shrink search space
                ans = min(ans , nums[low]);
                low = low + 1;
                high = high - 1;
                continue;
            }
            if(nums[low] <= nums[mid]){ // left half sorted

                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else{//right half soted

                ans = min(ans, nums[mid]);
                high = mid-1;
            }

        }
        return ans;
    }
};
