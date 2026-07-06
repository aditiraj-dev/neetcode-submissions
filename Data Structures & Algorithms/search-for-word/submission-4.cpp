class Solution {
public:
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    if(helper(board, word, i, j, 0)) return true;
                }
            }
        }

        return false;
    }

    bool helper(vector<vector<char>>& board, string word, int i, int j, int w) //explores paths and returns true if a path forms word
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[w] || board[i][j] == '#') return false;
        if(w == word.size() - 1) return true;
        board[i][j] = '#';
        bool res = helper(board, word, i + 1, j, w + 1) || helper(board, word, i - 1, j, w + 1) || helper(board, word, i, j + 1, w + 1) || helper(board, word, i, j - 1, w + 1);
        board[i][j] = word[w];
        return res;
    }
};
