class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        //for border Os, mark their groups as visited
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(i != 0 && i != ROWS - 1 && j != 0 && j != COLS - 1) continue;
                if(board[i][j] == 'O')
                {
                    mark(board, i, j, '#');
                }
            }
        }

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) continue;
                if(board[i][j] == 'O')
                {
                    helper(board, i, j);
                }
            }
        }

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(i != 0 && i != ROWS - 1 && j != 0 && j != COLS - 1) continue;
                if(board[i][j] == '#')
                {
                    mark(board, i, j, 'O');
                }
            }
        }
    }

    void mark(vector<vector<char>>& board, int i, int j, char c)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == c) return;

        board[i][j] = c;
        mark(board, i - 1, j, c);
        mark(board, i + 1, j, c);
        mark(board, i, j - 1, c);
        mark(board, i, j + 1, c);
    }

    void helper(vector<vector<char>>& board, int i, int j)
    {
        if(i <= 0 || j <= 0 || i >= board.size() - 1 || j >= board[0].size() - 1 || board[i][j] == 'X') return;

        board[i][j] = 'X';
        helper(board, i - 1, j);
        helper(board, i + 1, j);
        helper(board, i, j - 1);
        helper(board, i, j + 1);
    }
};
