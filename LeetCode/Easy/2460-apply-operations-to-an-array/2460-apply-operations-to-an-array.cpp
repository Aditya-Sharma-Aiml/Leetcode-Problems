class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans = nums;
        int n = nums.size();
        // operation
        for(int i=0 ; i<n-1 ; i++){
            if(ans[i] == ans[i+1]){
                ans[i] = ans[i]*2;
                ans[i+1] = 0;
            }
        }

        // move zero to end

        int j = -1;
        for(int i=0 ; i<n ; i++){
        // find frist zero
            if(ans[i]==0) {
                j=i;
                break;
            }
        }
        if (j==-1) return ans;
        for(int i=j+1 ; i<ans.size() ; i++){
            while(ans[i]!=0) swap(ans[i], ans[j++]);
        }
        return ans;
        
    }
};