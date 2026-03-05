class Solution {
public:

    vector<int>findNSEidx(vector<int>&arr){
        int n = arr.size();

        vector<int>NSEidx(n);
        stack<int>st;

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            NSEidx[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return NSEidx;
        
    }
    vector<int>findPSEidx(vector<int>&arr){

        int n = arr.size();

        vector<int>PSEidx(n);
        stack<int>st;

        for(int i=0;i<n; i++){

            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            PSEidx[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return PSEidx;
        
    }
   
    int sumSubarrayMins(vector<int>& arr) {

        vector<int>NSEidx = findNSEidx(arr);
        vector<int>PSEidx = findPSEidx(arr);

        int n = arr.size();
        int mod = (1e9+7);

        int minSum = 0;

        for(int i=0; i<n; i++){

            int left = i - NSEidx[i];
            int right = PSEidx[i]  - i;

            long long freq = left * right * 1LL;

            int  val = (arr[i] * freq * 1LL) % mod;

            minSum = (minSum + val) % mod;
        }
        return minSum;
    }
};