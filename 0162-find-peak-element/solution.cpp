class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // edge case
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        // handle over flow
        int low = 1 , high = n-2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // mid is peak
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }

            //peak is in right
            else if (nums[mid-1] < nums[mid]){
                low = mid + 1;
            }
            // peak is in left and also handle multiple peak problem
            else{
                high = mid - 1;
            }

        }
        return -1; // dummy return statement
    }
};
