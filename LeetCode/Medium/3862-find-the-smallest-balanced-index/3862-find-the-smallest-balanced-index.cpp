class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        // log(a∗b∗c)=loga+logb+logc  kyonki nums[i] <= 1e9

        int n = nums.size();
        vector<double>suffixLog(n+1, 0);

        for(int i = n-1 ; i>=0; i--){
            suffixLog[i] = suffixLog[i+1] + log((double)nums[i]);
        }

        long long  prefixsum = 0;

        for(int i=0; i<n ; i++){

            double rightlog = suffixLog[i+1];

            if(prefixsum >  0){
                //floating absolute value.
                if(fabs(log((double)prefixsum) - rightlog) < 1e-9)
                    return i;
            }
            prefixsum += nums[i];

        }
        return -1;

    }
};