class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // int res = nums.size();
        // for (int i = 0; i < nums.size(); i++) {
        //     res ^= i;
        //     res ^= nums[i];
        // }
        // return res;

        // xxxxxxxxx using cycle sort xxxxxxxxxx

        int i=0;
        int n = nums.size();

        while(i<n){

            int correctIndx = nums[i];
            if(nums[i]<n && nums[i] != nums[correctIndx]){
                swap(nums[i], nums[correctIndx]);
            }
            else i++;
        }
        for(int i=0; i<n; i++){

            if (nums[i] != i){
                return i;
            }
        }
        return n;

    }
};