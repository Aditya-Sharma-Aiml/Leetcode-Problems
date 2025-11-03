class Solution {
public:
    // Rotate the matrix 90° 
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transpose kro
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse kro each row ko
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) { 
            // k = 1-> 90 , 2-> 180 , 3-> 270 , 4-> 360 degree
            if (mat == target) return true; 
            rotate(mat);                    
        }
        return false;
    }
};
