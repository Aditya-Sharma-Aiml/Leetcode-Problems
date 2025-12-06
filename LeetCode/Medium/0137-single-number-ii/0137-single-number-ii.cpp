class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // track bits appearing once and twice

        for(int num : nums) {
            // ones → holds bits which have appeared 1 time modulo 3
            // twos → holds bits which have appeared 2 times modulo 3
            ones = (ones ^ num) & ~twos;
            // mask out kro joh twos me hai woh ones me na ho
            twos = (twos ^ num) & ~ones;
        }

        return ones; // 'ones' holds the single number
    }
};