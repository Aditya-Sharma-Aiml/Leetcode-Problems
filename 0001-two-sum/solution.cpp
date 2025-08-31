class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> map;
        int n = nums.size();

        for(int i = 0 ;i<n ; i++){
            int num = nums[i];
            int moreneeded = target - num;
            if(map.find(moreneeded) != map.end()){
                    return {i,map[moreneeded]};
           } 
           map[num]  = i; 
        }
        return {-1 , -1};
        
    }
};
