class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        while(1){

            auto it = find(nums.begin(), nums.end(), original);
            if (it == nums.end()) break;

            long long Double = 2LL * (long long)(*it);

            if (Double > INT_MAX) return (int)Double;

            int newVal = (int)Double;
            original = newVal;
            
        }
        return original;
    }
};