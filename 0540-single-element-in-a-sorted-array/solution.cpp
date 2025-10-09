class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //edge case
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];
        
        // handle overflow
        int low = 1 , high = n-2;

        while(low <= high){
            int mid = low + (high - low)/2;

            // mid => single element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            // we are in left half( index -> (even , odd))
            if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid-1])){
                    // eliminate left because single => single right me hai
                    low = mid + 1;
                }
            // we are in right half( index -> (odd , even))
            else {
                // eliminate right because single => single left me hai
                high = mid - 1;
            }


        }
        return -1;

    }
};
