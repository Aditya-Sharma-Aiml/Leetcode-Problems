class Solution {
private:
    vector<int>findNSEidx(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>nseIdx(n);

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nseIdx[i] = st.empty() ? n : st.top();
            st.push(i); 
        }
        return nseIdx;
    }
    vector<int>findPSEidx(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>pseIdx(n);

        for(int i=0; i<n ; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pseIdx[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return pseIdx;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>nseIdx = findNSEidx(heights);
        vector<int>pseIdx = findPSEidx(heights);

        int maxi = 0;
        for(int i=0; i<n; i++){

            int height = heights[i];
            int width = ( nseIdx[i] - pseIdx[i] - 1);

            maxi = max(maxi, height*width);
        }
        return maxi;
    }
};