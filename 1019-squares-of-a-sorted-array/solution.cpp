class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans(n);

        int left  = 0;
        int right = n-1;
        int pos = n-1;

        while(left<=right){

            int leftSquare = abs(nums[left]*nums[left]);
            int rightSquare = abs(nums[right]*nums[right]);

            if(leftSquare > rightSquare){
                ans[pos--] = leftSquare;
                left ++;
            }
            else{    
                ans[pos--] = rightSquare;
                right--;
            }

        }


        
        return ans;
    }
};
