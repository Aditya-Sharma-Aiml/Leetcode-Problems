class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        unordered_map<int,int>mpp;
        // Setting 0 in the map.
        mpp[0]=1;
        int preSum = 0;
        int count = 0;
        for(int i=0 ;i<n ;i++){

            preSum +=arr[i];
            // calculate s-k
            int rem = preSum -k;
            // Add the number of subarrays are remaining:
            if(mpp.count(rem)==1) count += mpp[rem];
            // Update the count of prefix sum  in the map
            mpp[preSum]++;
        }
        return count;
    }
};
