class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int posIndex = 0;
        int negIndex = 1;
        int n = nums.size();
        vector<int>ans(n,0);

        for(int num : nums){

            if(num>0){
                ans[posIndex] = num;
                posIndex +=2;

            }

            else{
                ans[negIndex] = num;
                negIndex+=2;
            }
        }

        return ans;
    }
};
