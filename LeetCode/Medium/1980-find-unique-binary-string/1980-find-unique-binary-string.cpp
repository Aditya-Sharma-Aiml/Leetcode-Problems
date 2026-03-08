class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //cantor diagonal method : 
        //Agar tumhare paas n strings hain (length n), 
        //toh tum diagonal elements ko flip karke 
        //ek nayi string bana sakte ho jo list me kabhi bhi nahi hogi.

        int n = nums.size();
        string ans = "";
        for(int i=0; i<n ; i++){
            ans += (nums[i][i] == '0') ?'1' : '0';
        }
        return ans;
    }
};