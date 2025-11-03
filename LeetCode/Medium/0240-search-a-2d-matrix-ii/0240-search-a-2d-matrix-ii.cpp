class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // start eleimination from top-right corner, 
        // you can also start from bottom-left corner. 
        // top-right : ascending sorted (row -> column)
        // bottom-left : ascending sorted (column -> row)
        int row = 0 , col = m-1; 

        while(row < n && col >= 0) {

            if(matrix[row][col] == target) return true;
            else if (target < matrix[row][col]) col--;
            else row ++;
        }
        return false;
    }
};