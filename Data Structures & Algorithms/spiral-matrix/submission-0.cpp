class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int ROWS = matrix.size(), COLS = matrix[0].size();
        int i = 0, j = 0;
        while ((int)res.size() < ROWS * COLS) {
            helper(i, j, matrix, ROWS, COLS, res);
            i++;
            j++;
        }
        return res;
    }

private:
    void helper(int i, int j, vector<vector<int>>& matrix, int ROWS, int COLS, vector<int>& res) {
        // top row: left to right
        for (int c = i; c <= COLS - i - 1; c++) {
            res.push_back(matrix[i][c]);
        }

        // right column: top+1 to bottom-1
        for (int r = j + 1; r < ROWS - i - 1; r++) {
            res.push_back(matrix[r][COLS - j - 1]);
        }

        // bottom row: right to left (only if it's a different row than the top)
        if (i < ROWS - i - 1) {
            for (int c = COLS - j - 1; c >= j; c--) {
                res.push_back(matrix[ROWS - i - 1][c]);
            }
        }

        // left column: bottom-1 up to top+1 (only if it's a different column than the right)
        if (j < COLS - j - 1) {
            for (int r = ROWS - i - 2; r >= i + 1; r--) {
                res.push_back(matrix[r][j]);
            }
        }
    }
};
