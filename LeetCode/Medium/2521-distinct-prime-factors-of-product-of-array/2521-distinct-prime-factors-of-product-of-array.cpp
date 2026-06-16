class Solution {
public:
    void prime(int n, set<int>&factors){
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                factors.insert(i);
                n /= i;
            }
        }

        if (n > 1)  // remaining prime factor
            factors.insert(n);

        
    }
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>st;

        for(int i=0; i<nums.size(); i++){
            prime(nums[i], st);

        }
        return st.size();

    }
};