class Solution {
    private:
        bool isValid(int row, int col, char c, vector<vector<char>>& board){

            // 1) check in rows and columns corressponding to index of c
            for(int i=0; i<9; i++){
                
                //if char already present in column -> not valid
                if(board[i][col] == c) return false;

                //if char already present in row -> not valid
                if(board[row][i] == c) return false;
            }

            // 2) check in (3x3) sub-box
            int boxRowStart = 3 * (row / 3);
            int boxColStart = 3 * (col / 3);

            for(int i=0; i<3 ; i++){
                for(int j=0; j<3 ; j++){

                    if( board[boxRowStart + i][boxColStart + j] == c) return false;
                }
            }

            //If all checks passed, placement of c is valid
            return true;
        }

        bool solve(vector<vector<char>>& board){

            // traverse and find empty cell
            for(int i=0 ; i<9; i++){
                for(int j=0; j<9; j++){

                    if(board[i][j] == '.'){

                        //check all the possibility
                        for(char c = '1' ; c <= '9' ; c++){

                            if(isValid(i, j, c, board)){
                                
                                board[i][j] = c;

                                // Recur to solve rest of the board
                                if(solve(board)) return true; 
                                // successful -> return true

                                // not successfull : solve(false)-> backtrack and remove c
                                board[i][j] = '.';

                            }
                        }
                        return false ; // if no digit can be placed    
                    }

                }
            }
            // all cell filled
            return true;
        }
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};