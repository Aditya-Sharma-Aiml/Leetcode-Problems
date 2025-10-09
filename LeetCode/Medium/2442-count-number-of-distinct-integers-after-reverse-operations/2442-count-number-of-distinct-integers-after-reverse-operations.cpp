class Solution {
public:
    int reverse(int n ){

        int rev = 0;
        while(n>0){
            int digit = n % 10;
            rev = rev *10 + digit;
            n /= 10;
        }
        return rev;   
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int>distinct;
        
        for(int i=0 ; i<n ; i++){
            distinct.insert(nums[i]);
            distinct.insert(reverse(nums[i]));
        }
        return distinct.size();

        
    }
};