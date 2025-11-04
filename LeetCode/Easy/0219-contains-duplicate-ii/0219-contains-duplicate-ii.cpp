class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int,int>map;

        for(int i=0 ; i<nums.size() ; i++){
            //are we seen before numms[i]
            if(map.find(nums[i]) != map.end()){
                // if seen then when 
                // and kya indices of this element satisfy abs(i - j) <= k.
                if(abs(map[nums[i]] - i) <= k) return true;
 
            }
            map[nums[i]] = i;

        }
        return false;
    }
};