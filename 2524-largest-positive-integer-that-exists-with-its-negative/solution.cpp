class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(), nums.end());
        int ans = -1;
        for(int num : nums){
            if (num > 0 && seen.count(-num)){
                ans = max(ans, num);
            }
        }
        return ans;
        // bool exist[1001] = {0}; // track positive numbers
        // int ans = -1;

        // for (int x : nums) {
        //     int val = abs(x);
        //     if (exist[val]) 
        //         ans = max(ans, val);
        //     else 
        //         exist[val] = true;
        // }
        // return ans;
    }
};
