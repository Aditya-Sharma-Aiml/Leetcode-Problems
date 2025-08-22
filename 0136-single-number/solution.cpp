class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xor = 0;
        for(int j : nums){
            Xor^=j;
        }
        return Xor;
    }
};
