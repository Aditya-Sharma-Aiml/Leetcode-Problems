class Solution {
public:
    void findCombination(int start, int k, int n,
                         vector<int>& nums, vector<vector<int>>& ans)
    {
        // Base case: exact k numbers use ho gaye 
        if (k == 0) {
            ans.push_back(nums);
            return;
        }

        // 1 se n tak numbers try karte hain, bina repeat ke
        for (int i = start; i <= n; i++) {

            nums.push_back(i); // number choose kiya

            // next index se call (i+1),k-1
            findCombination(i + 1, k - 1, n, nums, ans);

            nums.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>nums;
         findCombination(1, k, n, nums, ans);
         return ans;
    }
};