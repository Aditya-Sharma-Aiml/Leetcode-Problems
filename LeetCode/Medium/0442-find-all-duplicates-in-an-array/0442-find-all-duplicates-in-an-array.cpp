class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // vector<int>ans;

        // for(int i=0 ; i<nums.size() ; i++){
        //     // place a num to its ideal index (index 7 -> value 8)
        //     int index = abs(nums[i])-1;
        //     // mark as exist
        //     if(nums[index] > 0) nums[index] = -nums[index];
        //     // if again exist then push into ans
        //     else
        //         ans.push_back(abs(nums[i]));
        // }
        // return ans;

        // xxxxxxxxxxx using cycle sort xxxxxxxxxxxxxxxxxx

        int i=0;
        while(i<nums.size()){

            int correctIndx = nums[i] - 1;
            
            if (nums[i] != nums[correctIndx]){
                swap(nums[i], nums[correctIndx]);
            }
            else i++;
        }

        vector<int>duplicates;
        for(int i=0; i<nums.size(); i++){
            // let nums[0] != 1
            if(nums[i] != i+1){
                duplicates.push_back(nums[i]);
            }
        }
        return duplicates;

    }
};