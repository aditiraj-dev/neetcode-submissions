class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int top = 0, bot = ROWS - 1;

        while(top <= bot)
        {
            int m = (top + bot)/2;
            if(target > matrix[m][COLS - 1]) top = m + 1;
            else if(target < matrix[m][0]) bot = m - 1;
            else break;
        }

        if(!(top <= bot)) return false;

        int row = (top + bot)/2;

        int l = 0, r = COLS - 1;

        while(l <= r)
        {
            int m = (l + r)/2;
            if(matrix[row][m] == target) return true;
            else if(matrix[row][m] < target) l = m + 1;
            else r = m - 1;
        }

        return false;
    }
};
