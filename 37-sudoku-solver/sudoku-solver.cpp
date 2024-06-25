class Solution {
private:
    void ans(vector<vector<char>>& board, vector<vector<char>>& curr, int i, int j, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& mat) {
        // Find the next empty cell
        while(i < 9 && board[i][j] != '.') {
            if (j < 8)
                j++;
            else {
                j = 0;
                i++;
            }
        }

        // If we have reached the end of the board, we have found a solution
        if(i == 9) {
            curr = board;
            return;
        }

        // Try different numbers from 1 to 9
        for(int k = 1; k <= 9; k++) {
            // If a solution has already been found, exit the loop
            if(curr.size() > 0)
                break;

            // Check if the current number k is valid for the current cell
            if(!col[j][k] && !row[i][k] && !mat[3*(i/3) + (j/3)][k]) {
                // Mark the current number k as used
                col[j][k] = true;
                row[i][k] = true;
                mat[3*(i/3) + (j/3)][k] = true;

                // Place the current number k in the current cell
                board[i][j] = (char)('0'+k);

                // Recursively solve the Sudoku puzzle
                ans(board, curr, i, j, col, row, mat);

                // Undo the current number k and mark it as unused
                col[j][k] = false;
                row[i][k] = false;
                mat[3*(i/3) + (j/3)][k] = false;
                board[i][j] = '.';
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> mat(9, vector<bool>(10, false));
        vector<vector<char>> curr;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    mat[3*(i/3) + (j/3)][x] = true;
                }
            }
        }

        ans(board, curr, 0, 0, col, row, mat);
        board = curr;
        return;
    }
};