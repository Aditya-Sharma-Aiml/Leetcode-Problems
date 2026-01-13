class Solution {
    private:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n,
                vector<int>&leftRow,
                vector<int>&lowerDiagonal,
                vector<int>&upperDiagonal ){

                    // base case
                    if( col == n){
                        ans.push_back(board);
                        return ;
                    }

                    for(int row=0; row<n ; row++){

                        // check hash arrays to find safe (0) or not (1)
                        if (leftRow[row] == 0 &&
                            lowerDiagonal[row + col] == 0 &&
                            upperDiagonal[( n-1 ) + (col - row)] == 0 ){
                                
                                // fill queen
                                board[row][col] = 'Q';

                                // mark in hashArray
                                leftRow[row] = 1;
                                lowerDiagonal[row + col] = 1;
                                upperDiagonal[( n-1 ) + (col - row)] = 1;

                                // recursion call
                                solve(col+1, board, ans, n, 
                                        leftRow, 
                                        lowerDiagonal, 
                                        upperDiagonal);

                                // backtrack 
                                board[row][col] = '.'; // empty 

                                // un-mark in hashArray
                                leftRow[row] = 0;
                                lowerDiagonal[row + col] = 0;
                                upperDiagonal[( n-1 ) + (col - row)] = 0;

                            }
                    }
                }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));

        // hash array for marking 
        vector<int>leftRow(n,0);
        vector<int>lowerDiagonal(2*n-1 ,0);
        vector<int>upperDiagonal(2*n-1 ,0);

        solve(0, board, ans, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};