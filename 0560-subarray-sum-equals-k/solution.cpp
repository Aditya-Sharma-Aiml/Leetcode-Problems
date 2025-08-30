class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        unordered_map<long long, int> freq;
        freq[0] = 1;  
        long long sum = 0;
        int count = 0;

        for (int x : arr) {
            sum += x;

           
            if (freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }

            freq[sum]++; 
        }

        return count;
    }
};
