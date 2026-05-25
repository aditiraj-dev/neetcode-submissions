class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowS;
        unordered_map<int, unordered_set<char>> colS;
        map<pair<int, int>, unordered_set<char>> grid;

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.') continue;

                if(rowS[r].count(board[r][c]) || colS[c].count(board[r][c])) return false;
                int rowK = r / 3, colK = c / 3;
                if(grid[{rowK, colK}].count(board[r][c])) return false;

                grid[{rowK, colK}].insert(board[r][c]);
                rowS[r].insert(board[r][c]);
                colS[c].insert(board[r][c]);
            }
        }

        return true;
    }
};
