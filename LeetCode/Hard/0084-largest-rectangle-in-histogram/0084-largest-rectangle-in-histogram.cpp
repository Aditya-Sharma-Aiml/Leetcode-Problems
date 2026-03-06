class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int>st;

        int maxArea = 0; // area = arr[i] * (nse - pse - 1)

        for(int i=0; i<=n; i++){

            while(!st.empty() 
                    && (i==n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()]; // arr[i]
                st.pop();

                int width = 0;

                if(st.empty()){ // edge case
                    width = i;
                }
                else{
                    width = i - st.top() - 1; // (nse-pse-1)
                }

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};