class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int,int>, unordered_set<char>> grid;

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.') continue;

                if(rows[r].count(board[r][c]) || cols[c].count(board[r][c])) return false;

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                
                int R = r / 3, C = c / 3;

                if(grid[{R, C}].count(board[r][c])) return false;
                grid[{R, C}].insert(board[r][c]);

            }
        }

        return true;
    }
};
