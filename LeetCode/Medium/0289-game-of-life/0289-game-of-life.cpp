class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                int alive = 0;

                for(int k = 0; k < 8; k++){
                    int di = i + dx[k];
                    int dj = j + dy[k];

                    // 1	alive → alive
                    // 0	dead → dead
                    // -1	alive → dead
                    // 2	dead → alive

                    if(di >= 0 && di < n && dj >= 0 && dj < m &&
                      (board[di][dj] == 1 || board[di][dj] == -1))
                    {
                        alive++;
                    }
                }

                if(board[i][j] == 1){
                    if(alive < 2 || alive > 3)
                        board[i][j] = -1;   // alive → dead
                }
                else{
                    if(alive == 3)
                        board[i][j] = 2;    // dead → alive
                }
            }
        }

        // normalize final board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == -1) board[i][j] = 0;
            }
        }
    }
};
