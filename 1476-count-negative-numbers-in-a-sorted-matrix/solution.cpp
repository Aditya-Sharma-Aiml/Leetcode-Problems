class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        // // O(mlogn)
        // int n = grid.size();
        // int neg = 0;

        // for(int i= 0 ; i<n ;i++){
            
        //     int low = 0 , high = grid[i].size()-1;
        //     int indx = -1;

        //     while(low<=high){

        //         int mid = (low+high)/2;

        //         if(grid[i][mid] < 0){
        //             indx = mid;
        //             high = mid-1;
        //         }
        //         else low = mid+1;
        //     }
        //     if (indx != -1) 
        //         neg += grid[i].size() - indx ;
        // }
        // return neg;

        //  xxxxxxxxxxxxxxxx xxxxx xxxxxxxxxxxxx

        // O(m+n)
        int m = grid.size(), n = grid[0].size();
        int i = m - 1, j = 0, neg = 0;
        
        while (i >= 0 && j < n) {

            if (grid[i][j] < 0) {
                
                neg += (n - j); // all elements from j to n-1 are negative
                i--;            // move up
            } else {
                j++;            // move right
            }
        }
        return neg;

        
    }
};
