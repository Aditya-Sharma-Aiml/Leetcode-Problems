class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>prefixMax(n);
        vector<int>suffixMax(n);

        //prefix max of each element
        prefixMax[0] = height[0];
        for(int i=1; i<n ; i++){

            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        //suffix max of each element
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0 ; i--){

            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        // calculate total unit of water trapped
        int total = 0;
        for(int  i=0; i<n; i++){

            int leftMax = prefixMax[i]; // curr prefix max
            int rightMax = suffixMax[i]; // curr suffix max

            total += min(leftMax, rightMax) - height[i];
            
        }
        return total;
    }
};