class Solution {
public:
    int countPartitions(vector<int> &a, int maxSum) {

        int n = a.size(); 

        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) {

            if (subarraySum + a[i] <= maxSum) {
                //insert element to current subarray
                subarraySum += a[i];
            }
            else {
                //insert element to next subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& a, int k) {
        // same as book Allocationn  problem

        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);

        //Apply binary search:
        while (low <= high) {

            int mid = (low + high) / 2; //mid -> maxSum

            int partitions = countPartitions(a, mid);

            if (partitions > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};