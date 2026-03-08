class Solution {
private:
    vector<int>findNSEidx(vector<int>&nums){
        int n = nums.size();

        stack<int>st;
        vector<int>nseIdx(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            nseIdx[i] = !st.empty() ? st.top() : n;
            
            st.push(i);

        }
        return nseIdx;

    }
    vector<int>findPSEEidx(vector<int>&nums){
        int n = nums.size();

        stack<int>st;
        vector<int>pseeIdx(n);

        for(int i=0; i<n; i++){

            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            pseeIdx[i] = !st.empty() ? st.top() : -1;
            
            st.push(i);

        }
        return pseeIdx;

    }
    vector<int>findNGEidx(vector<int>&nums){
        int n = nums.size();

        stack<int>st;
        vector<int>ngeIdx(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            ngeIdx[i] = !st.empty() ? st.top() : n;
            
            st.push(i);

        }
        return ngeIdx;

    }
    vector<int>findPGEEidx(vector<int>&nums){
        int n = nums.size();

        stack<int>st;
        vector<int>pgeeIdx(n);

        for(int i=0; i<n; i++){

            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            pgeeIdx[i] = !st.empty() ? st.top() : -1;
            
            st.push(i);

        }
        return pgeeIdx;

    }
    long long sumSubarrayMin(vector<int>& nums){

        int n = nums.size();

        vector<int>nseIdx = findNSEidx(nums);
        vector<int>pseeIdx = findPSEEidx(nums);

        long long minSum = 0;

        for(int i=0; i<n ; i++){

            int left = i - nseIdx[i];
            int right = pseeIdx[i] - i;

            long long freq = (left * right) * 1LL;
            long long val =( nums[i] * freq )* 1LL;

            minSum += val;

        }
        return minSum;

    }
    long long sumSubarrayMax(vector<int>& nums){

        int n = nums.size();

        vector<int>ngeIdx = findNGEidx(nums);
        vector<int>pgeeIdx = findPGEEidx(nums);

        long long maxSum = 0;

        for(int i=0; i<n ; i++){

            int left = i - ngeIdx[i];
            int right = pgeeIdx[i] - i;

            long long freq = (left * right) * 1LL;
            long long val =( nums[i] * freq )* 1LL;

            maxSum += val;

        }
        return maxSum;

    }
public:
    long long subArrayRanges(vector<int>& nums) {

        return (sumSubarrayMax(nums)  - sumSubarrayMin(nums));
    }
};