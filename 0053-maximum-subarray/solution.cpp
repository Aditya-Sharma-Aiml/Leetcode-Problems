class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;

        for(int i=0 ; i<n ; i++){

            sum += arr[i];
            maxi = max(maxi,sum);
            if(sum<0) sum = 0;

        }
        return maxi; // handle when array does not have any positive number and the maxsum exist in -ve then return 0
    }
};
