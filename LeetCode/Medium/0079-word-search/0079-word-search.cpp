class Solution {
    private:
        bool searchDFS(int idx, int i, int j, vector<vector<char>>& board, string word){
            
            if(idx == word.size()) return true;

            // check boundaries
            if (i<0 || j<0 ||
                 i>= board.size() || j>=board[0].size() ||
                 board[i][j] == '#' || 
                 board[i][j] != word[idx]){

                    return false;
                 }

            char temp = board[i][j];
            board[i][j] = '#'; // mark visited

            // try for all possible path(down, left, right, up)
            bool found =searchDFS(idx+1 , i+1, j, board, word) ||
                        searchDFS(idx+1 , i, j-1, board, word) ||
                        searchDFS(idx+1 , i, j+1, board, word) ||
                        searchDFS(idx+1 , i-1, j, board, word);

            board[i][j] = temp; // backtrack and unmark;
            return found;

        }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // find first char which == word first char
        for(int i=0; i<m ; i++){
            for(int j=0; j<n ; j++){

                if (searchDFS(0, i, j, board, word)){
                    return true;    
                }
            }
        }
        return false;
    }
};