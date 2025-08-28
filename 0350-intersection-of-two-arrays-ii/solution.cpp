class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int,int>count;

        vector<int>result;
        for(auto num1 : nums1){
            count[num1]++;
        }
        for(auto num2 : nums2){
            if(count[num2]>0){
                result.push_back(num2);
                count[num2]--;
            }
        }
        return result ; 
    }
};
