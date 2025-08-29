class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xorall = 0;
        for(int j : nums){
            Xorall^=j;
        }
        return Xorall;
    }
};
