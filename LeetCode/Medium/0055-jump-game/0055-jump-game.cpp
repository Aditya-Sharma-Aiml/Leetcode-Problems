class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i=-1;
        if(n==1) return true;
        for(int i=0 ; i<n ; i++){
            i+=nums[i];
            if(i>n || i==0) return false;
        }
        return true;
    }
};