class Solution {
private :
    int largestRectangleArea(vector<int>&arr){

        stack<int>st;
        int n = arr.size();
        int maxA = 0;

        for(int i=0; i<=n; i++){

            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){

                int height = arr[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                
                //xxxxxxxxx only change in maximal rectangle xxxxx
                int side = min(height, width);   // square side
                maxA = max(maxA, side * side);   // square area
                // xxxxxx xxxxxxxxx xxxxxxx
            }

            st.push(i);
        }
        return maxA;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.empty()) return 0;

        int m = matrix[0].size();
        
        vector<int>heights(m,0);

        int maxArea = 0;
        for(auto &row : matrix){

            for(int i=0; i<m; i++){
                
                if(row[i] == '1') heights[i]++;
                else heights[i] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};